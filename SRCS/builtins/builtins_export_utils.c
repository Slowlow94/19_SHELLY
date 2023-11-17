/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:33:02 by salowie           #+#    #+#             */
/*   Updated: 2023/11/17 10:34:55 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	is_char(char *str, char c)
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

int	ft_strlen_double_tab(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}

int	is_special_caracter(char *var)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (var[i])
	{
		if (ft_isalpha(var[0]) == 0)
			return (1);
		if (var[i] == '+' && var[i + 1] == '=')
			i++;
		if (var[i] == '=')
			flag = 1;
		while (flag == 1 && (var[i] == '+' || var[i] == '*' || var[i] == '-' 
				|| var[i] == '/' || var[i] == '%' || var[i] == ',' 
				|| var[i] == '.'))
			i++;
		if (!(var[i] >= 'A' && var[i] <= 'Z') 
			&& !(var[i] >= 'a' && var[i] <= 'z') 
			&& !(var[i] >= '0' && var[i] <= '9') && !(var[i] == '='))
			return (1);
		i++;
	}
	return (0);
}
