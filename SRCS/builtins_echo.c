/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:03:07 by salowie           #+#    #+#             */
/*   Updated: 2023/10/30 12:03:20 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	ft_echo(char **str, int i)
{
	int	j;

	j = 0;
	if (ft_strncmp(str[i + 1], "-n", 2) == 0)
	{
		while (str[i + 2][j] && str[i + 2][j] != '\n')
		{
			printf("%c", str[i + 2][j]);
			j++;
		}
	}
	else
		printf("%s\n", str[i + 1]);
	return (0);
}