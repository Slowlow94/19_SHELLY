/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:03:07 by salowie           #+#    #+#             */
/*   Updated: 2023/12/27 13:03:19 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static int	is_nnn(char **str, int i)
{
	int	j;

	if (!str[i])
		return (1);
	if (ft_strncmp(str[i], "-n", 2) == 0)
	{
		j = 2;
		while (str[i][j])
		{
			if (str[i][j] && str[i][j] == 'n')
				j++;
			else
				return (1);
		}
		return (0);
	}
	return (1);
}

static void	print_echo(char **str, int i, int n)
{
	while (str[i])
	{
		if (str[i + 1] == NULL)
			printf("%s", str[i]);
		else
			printf("%s ", str[i]);
		i++;
	}
	if (n == 0)
		printf("\n");
}

int	ft_echo(char **str, int i)
{
	int	n;

	n = 0;
	if (!str[i])
		print_echo(str, i, 0);
	while (str[i])
	{
		if (is_nnn(str, i) == 0)
			n = 1;
		else if (ft_strncmp(str[i], "-n", 3) == 0)
			n = 1;
		else
			break ;
		i++;
	}
	if (str[i])
		print_echo(str, i, n);
	return (0);
}
