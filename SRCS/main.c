/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:40:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 15:45:28 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/minishell.h"

t_shell	g_shell;

void	ft_print_cmds(char **cmd);

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	if (env[0] == NULL)
	{
		printf("%s\n", ENV);
		return (1);
	}
	if (ft_initshell(env) == 1)
		return (1);
	while (1)
	{
		ft_signal();
		g_shell.cmd_line = readline(" minishell $> ");
		if (!g_shell.cmd_line)
			ft_main_exit();
		g_shell.cmds_redir = ft_parse(g_shell.cmd_line, g_shell.my_env);
		if (g_shell.cmds_redir)
			ft_process();
		if (ft_clean() == 1)
			return (1);
	}
	ft_free_all(&g_shell);
	return (0);
}
