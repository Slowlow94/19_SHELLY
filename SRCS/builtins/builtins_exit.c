/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:35:40 by salowie           #+#    #+#             */
/*   Updated: 2023/12/21 17:52:47 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_exit(char *argv)
{
	int	value;
	int	i;

	if (g_shell.pipex.pipe_nbr == 0)
		printf("exit\n");
	ft_free_all(&g_shell);
	if (!argv)
		exit(g_shell.status);
	i = 0;
	while (argv[i])
	{
		if (ft_isalpha(argv[i]) == 1)
		{
			printf("exit: %s: numeric argument required\n", argv);
			exit (255);
		}
		i++;
	}
	value = ft_atoi(argv);
	exit (value);
}
