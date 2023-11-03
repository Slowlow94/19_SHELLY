/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:35:40 by salowie           #+#    #+#             */
/*   Updated: 2023/11/02 10:38:14 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	ft_exit(char *argv)
{
	int	value;
	int	i;

	printf("exit\n");	
	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
	{
		if (ft_isalpha(argv[i]) == 1)
		{
			printf("exit: %s: numeric argument required\n", argv);
			return (1);
		}
		i++;
	}
	value = ft_atoi(argv);	
	if (value == 0)
		return (0);
	return (1);
}
