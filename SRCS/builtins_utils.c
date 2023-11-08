/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:33:02 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 17:59:55 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	is_equal(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_equal_str(char *stack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = 0;
		if (stack[i] == needle[j])
		{
			if (stack[i + 1] == needle[j + 1] && needle[j + 1] && stack[i + 1])
				return (1);
		}
		i++;
	}
	return (0);
}

int	nbr_variables_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}
