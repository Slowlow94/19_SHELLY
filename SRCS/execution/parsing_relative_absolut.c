/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_relative_absolut.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:10:54 by salowie           #+#    #+#             */
/*   Updated: 2023/12/19 17:11:58 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_absolut_path(t_pipe *pipex, char **cmd, int i)
{
	int	index;
	int	lenght;
	int	d_len;

	index = ft_where_is_char(cmd[0]);
	d_len = ft_strlen_double_tab(cmd);
	lenght = ft_strlen(cmd[0]);
	pipex->decomp_cmd = malloc(sizeof(char *) * (d_len + 1));
	if (!pipex->decomp_cmd)
		ft_error_free_and_close(&g_shell, "Malloc failed :");
	pipex->decomp_cmd[0] = ft_substr(cmd[0], index + 1, lenght - (index + 1));
	while (cmd && cmd[i])
	{
		pipex->decomp_cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	pipex->decomp_cmd[i] = NULL;
	pipex->decomp_path = malloc(sizeof(char *) * 2);
	if (!pipex->decomp_path)
		ft_error_free_and_close(&g_shell, "Malloc failed :");
	pipex->decomp_path[0] = ft_substr(cmd[0], 0, index);
	pipex->decomp_path[1] = NULL;
	if (!pipex->decomp_path || !pipex->decomp_cmd)
		ft_error_free_and_close(&g_shell, "Wrong path or command :");
}

void	ft_relative_path(t_pipe *pipex, char **cmd, char *start)
{
	char	*path_envp;

	start = looking_for_start(g_shell.my_env, "PATH=", 4);
	if (!start)
		ft_error_free_and_close(&g_shell, "No path found :");
	path_envp = ft_substr(start, 5, ft_strlen(start) - 1);
	pipex->decomp_cmd = cmd;
	pipex->decomp_path = ft_split(path_envp, ':');
	free(path_envp);
	if (!pipex->decomp_path || !pipex->decomp_cmd)
		ft_error_free_and_close(&g_shell, "Wrong path or command :");
}
