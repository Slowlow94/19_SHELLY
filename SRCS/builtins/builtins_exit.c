/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:35:40 by salowie           #+#    #+#             */
/*   Updated: 2024/01/02 16:46:43 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_exit(char **argv, int i, int j)
{
	int		value;

	if (g_shell.pipex.pipe_nbr == 0)
		printf("exit\n");
	if (!argv[i])
	{
		ft_free_all(&g_shell);
		exit(g_shell.status);
	}
	if (argv[2])
	{
		printf("Minishell : exit: too many arguments\n");
		return (1);
	}
	while (argv[1][j])
	{
		if (ft_isalpha(argv[1][j]) == 1)
		{
			printf("exit: %s: numeric argument required\n", argv[1]);
			exit (255);
		}
		j++;
	}
	value = ft_atoi(argv[i]);
	exit (value);
}
