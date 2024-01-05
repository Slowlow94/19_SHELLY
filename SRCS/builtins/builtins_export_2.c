/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:51:38 by salowie           #+#    #+#             */
/*   Updated: 2024/01/02 12:19:55 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	is_var_exists(char **envp, char *var)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, until(var, '=') + 1) == 0 
			|| ft_strncmp(envp[i], var, until(var, '+')) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_from(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		j++;
		i++;
	}
	return (j);
}

int	until(char *var, char c)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != c)
		i++;
	return (i);
}

void	ft_strlcpy_whithout_plus(char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!src)
		return ;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			if (src[i] == '=')
				flag = 1;
			if (flag == 0 && src[i] == '+')
				i++;
			if (src[i] == 39 || src[i] == '"')
				i++;
			else
				dst[j++] = src[i++];
		}
		dst[j] = '\0';
	}
}

void	cpy_for_add_var(char *dst, char *src_add, char *src, int size)
{
	int	i;
	int	index_from_src;

	i = 0;
	index_from_src = until(src_add, '+') + 2;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (src_add[index_from_src] && i < size)
	{
		if (src_add[index_from_src] == 39 || src_add[index_from_src] == '"')
			index_from_src++;
		else
			dst[i++] = src_add[index_from_src++];
	}
	dst[i] = '\0';
}
