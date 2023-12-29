/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:21:40 by gvardaki          #+#    #+#             */
/*   Updated: 2023/12/26 15:14:26 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/minishell.h"

int	ft_initshell(char **env)
{
	g_shell.cmd_line = NULL;
	g_shell.cmds_redir = NULL;
	g_shell.my_env = create_my_envp(env);
	if (!g_shell.my_env)
	{
		ft_free_2d_char(&g_shell.my_env);
		return (1);
	}
	g_shell.export = NULL;
	g_shell.token_list = NULL;
	g_shell.elem_to_pipe = NULL;
	g_shell.pipex.decomp_cmd = NULL;
	g_shell.pipex.decomp_path = NULL;
	g_shell.status = 0;
	g_shell.env = false;
	tcgetattr(STDIN_FILENO, &g_shell.term);
	return (0);
}

void	ft_clean(void)
{
	ft_free_2d_char(&g_shell.cmds_redir);
	g_shell.pipex.pipe_nbr = 0;
	ft_lc_clear(&g_shell.elem_to_pipe);
	ft_free_struct(&g_shell.pipex);
}
