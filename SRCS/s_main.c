/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:40:57 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 17:57:27 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shelly	shell;
	int			i;
	(void)		argc;

	i = 0;
	shell.my_envp = create_my_envp(envp);
	// shell.my_args = ; PARTIE GUILLAUME
	while (argv[i])
	{
		// system("leaks a.out");
		if (ft_strncmp(argv[i], "echo", 5) == 0)
			return (ft_echo(argv, i + 1));
		else if (ft_strncmp(argv[i], "cd", 3) == 0)
			return (ft_cd(argv[i + 1]));
		else if (ft_strncmp(argv[i], "cd/", 3) == 0)
			return (printf("%s: No such file or directory\n", argv[i]));
		else if (ft_strncmp(argv[i], "pwd", 4) == 0)
			return (ft_pwd());
		else if (ft_strncmp(argv[i], "env", 4) == 0)
			return (ft_envp(shell.my_envp, argv, i));
		else if (ft_strncmp(argv[i], "export", 7) == 0)
			return (ft_export(shell.my_envp, argv[i + 1]));
		else if (ft_strncmp(argv[i], "exit", 5) == 0)
			return (ft_exit(argv[i + 1]));
		else if (i > 0)
			return (printf("%s: command not found\n", argv[i]));
		i++;
	}
	return (0);
}
