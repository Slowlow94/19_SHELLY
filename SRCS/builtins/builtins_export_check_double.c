/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_check_double_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:41:59 by salowie           #+#    #+#             */
/*   Updated: 2023/11/16 14:43:01 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	is_already_in_export(char **check_to, char *var)
{
	int	i;
	int	equal_index;

	equal_index = ft_strlen(var);
	i = 0;
	if (!check_to)
		return (0);
	while (check_to[i])
	{
		if (equal_index > 2)
		{
			if (ft_strncmp(check_to[i], var, until(var, '=') - 1) == 0)
				return (1);
		}
		else
		{
			if (ft_strncmp(check_to[i], var, 1) == 0 && check_to[i][1] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_non_var_in_env(char **to_check, char *var)
{
	int	i;
	int	equal_index;

	equal_index = ft_strlen(var);
	i = 0;
	while (to_check[i])
	{
		if (equal_index != 1)
		{
			if (ft_strncmp(to_check[i], var, until(to_check[i], '=') - 1) == 0)
			{
				if (to_check[i][equal_index] == '=')
					return (1);
			}
		}
		else
		{
			if (ft_strncmp(to_check[i], var, 1) == 0 && to_check[i][1] == '=')
				return (1);
		}
		i++;
	}
	return (0);
}
