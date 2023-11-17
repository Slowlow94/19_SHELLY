/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:10:09 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/16 16:13:50 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/minishell.h"

t_shell	g_shell;

void	ft_print_cmds(char **cmd);

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char **cmds;
	g_shell.my_envp = create_my_envp(env);
	g_shell.export = NULL;
	// eventuellement des check de secu

	while (1)
	{
		//initialisation diverses et recup d'env, path,...

		g_shell.cmd_line = readline("minishell $> ");
		cmds = ft_parse(g_shell.cmd_line, env);

		//ft_exec(cmds);
		exec_builtins(cmds);
		// ft_print_cmds(cmds);

		//cleaning, free, ...
		ft_free_2d_char(cmds, g_shell.cmd_nbr);

		//gestion signaux
	}
	return (0);
}

void	ft_print_cmds(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		printf("cmd [%d] = %s\n", i, cmd[i]);
		++i;
	}
}
