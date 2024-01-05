/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:34:01 by salowie           #+#    #+#             */
/*   Updated: 2024/01/03 10:58:08 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	*looking_for_start(char **str, const char *s2, int size)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && ft_strncmp(str[i], s2, size) == 0)
			return (str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_3(char const *s1, char c, char const *s2)
{
	char	*res;
	int		i;

	i = 0;
	if (!s1 || !s2 || !c)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	res[i++] = c;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

void	parsing_path(t_pipe *pipex, char **cmd)
{
	char	*start;
	int		i;

	start = NULL;
	i = 1;
	if (!cmd)
		return ;
	if (is_char(cmd[0], '/') == 1)
		ft_absolut_path(pipex, cmd, i);
	else
		ft_relative_path(pipex, cmd, start);
}

int	ft_where_is_char(char *cmd)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			index = i;
		i++;
	}
	return (index);
}

void	check_cmd(t_pipe pipex)
{
	char	*cmd;
	int		i;

	i = -1;
	while (pipex.decomp_path && pipex.decomp_path[++i])
	{
		cmd = ft_strjoin_3(pipex.decomp_path[i], '/', pipex.decomp_cmd[0]);
		if (!cmd)
		{
			free(cmd);
			ft_error_free_and_close(&g_shell, "ft_strjoin failed :");
		}
		if (access(cmd, X_OK) == 0)
		{
			execve(cmd, pipex.decomp_cmd, g_shell.my_env);
			perror(cmd);
			free(cmd);
			g_shell.pipex.status = 2;
			return ;
		}
		free(cmd);
	}
	perror(pipex.decomp_cmd[0]);
	ft_free_struct(&pipex);
	g_shell.pipex.status = 127;
}
