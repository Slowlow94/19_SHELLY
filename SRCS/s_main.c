/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:40:57 by salowie           #+#    #+#             */
/*   Updated: 2023/10/30 12:04:59 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	// char	*input;

	(void) argc;
	// while (1)
	// {
		// input = readline("SHELLY : ");
		// if (input == NULL)
		// 	break ;
		i = 0;
		while (argv[i])
		{
			// system("leaks a.out");
			if (ft_strncmp(argv[i], "echo", 5) == 0)
				return (ft_echo(argv, i));
			else if (ft_strncmp(argv[i], "cd", 3) == 0)
				return (ft_cd(argv[i + 1]));
			else if (ft_strncmp(argv[i], "pwd", 4) == 0)
				return (ft_pwd());
			else if (ft_strncmp(argv[i], "env", 4) == 0)
				return (ft_envp(envp));
			else if (ft_strncmp(argv[i], "export", 7) == 0)
				return (ft_export(envp, argv[i + 1]));
			i++;
		}
		// free(input);
	// }
	return (0);
}
