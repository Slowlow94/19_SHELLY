/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:33:02 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 14:40:08 by salowie          ###   ########.fr       */
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

static int	bef_equal(char *var)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (var[0] == '=')
		res = 1;
	while (var[i] && var[i] != '=')
	{
		if (var[0] && ft_isalpha(var[0]) == 0
			&& (var[0] != '"' && var[0] != 39))
			res = 1;
		if (!(var[i] == 39 || var[i] == '"' 
				|| ft_isalnum(var[i]) == 1 || var[i] == '+'))
			res = 1;
		i++;
	}
	return (res);
}

static int	after_equal(char *var, int i)
{
	int	quote;
	int	res;

	quote = 0;
	res = 0;
	while (var[i])
	{
		if (var[i] == 39 || var[i] == '"')
			quote = 1;
		else if (quote == 0 && var[i] == 32)
			res = 1;
		i++;
	}
	return (res);
}

int	is_special_caracter(char *var)
{
	int	i;
	int	res;

	if (ft_strncmp(var, "\"\"", ft_strlen(var)) == 0)
		return (1);
	res = bef_equal(var);
	if (res == 1)
		return (res);
	i = until(var, '=');
	res = after_equal(var, i);
	return (res);
}
