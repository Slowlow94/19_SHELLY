/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:21:40 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 15:46:32 by gvardaki         ###   ########.fr       */
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
	g_shell.signal = 0;
	g_shell.env = false;
	g_shell.here_doc = false;
	tcgetattr(STDIN_FILENO, &g_shell.term);
	return (0);
}

int	ft_clean(void)
{
	if (g_shell.signal != 0)
		g_shell.status = g_shell.signal;
	if (g_shell.here_doc == true)
	{
		if (unlink("/tmp/heredoc_tmp") == -1)
		{
			perror("/tmp/heredoc_tmp");
			return (1);
		}
	}
	ft_free_2d_char(&g_shell.cmds_redir);
	g_shell.pipex.pipe_nbr = 0;
	ft_lc_clear(&g_shell.elem_to_pipe);
	ft_free_struct(&g_shell.pipex);
	g_shell.signal = 0;
	return (0);
}

void	ft_main_exit(void)
{
	ft_free_2d_char(&g_shell.my_env);
	ft_free_all(&g_shell);
	exit(g_shell.status);
}
