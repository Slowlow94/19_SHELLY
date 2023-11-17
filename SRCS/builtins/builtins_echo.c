/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:03:07 by salowie           #+#    #+#             */
/*   Updated: 2023/11/14 11:08:12 by salowie          ###   ########.fr       */
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

static int	is_more_n(char **str, int i)
{
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (ft_strncmp(str[i], "-n", 3) == 0)
			i++;
		else
			return (1);
	}
	return (0);
}

static void	echo_with_no_n(char **str, int i)
{
	if (is_nnn(str, i) == 0 || ft_strncmp(str[i], "-n", 3) == 0)
	{
		while (str[++i])
		{
			if (str[i + 1] == NULL && (!(ft_strncmp(str[i], "-n", 3) == 0)))
				printf("%s", str[i]);
			else if (!(ft_strncmp(str[i], "-n", 3) == 0))
				printf("%s ", str[i]);
		}
	}
}

static void	echo_with_n(char **str, int i)
{
	while (str[i])
	{
		if (str[i + 1] == NULL)
			printf("%s", str[i]);
		else
			printf("%s ", str[i]);
		i++;
	}
	printf("\n");
}

int	ft_echo(char **str, int i)
{
	if (str[i])
	{
		if (is_nnn(str, i) == 1)
			echo_with_n(str, i);
		else if ((ft_strncmp(str[i], "-n", 3) == 0) 
			&& (is_more_n(str, i + 1) == 0))
			echo_with_no_n(str, i);
		else if (is_nnn(str, i) == 0 || ft_strncmp(str[i], "-n", 3) == 0)
			echo_with_no_n(str, i);
	}
	else
		echo_with_n(str, i);
	return (0);
}
