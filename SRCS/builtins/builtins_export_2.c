/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:51:38 by salowie           #+#    #+#             */
/*   Updated: 2023/11/16 12:21:21 by salowie          ###   ########.fr       */
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

	i = 0;
	j = 0;
	if (!src)
		return ;
	if (size != 0)
	{
		while (src[i] && i < size -1)
		{
			if (src[i] == '+')
				i++;
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
}

void	cpy_for_add_var(char *dst, char *src_add, char *src, int size)
{
	int	i;
	int	index_from_src_add;

	i = 0;
	index_from_src_add = until(src_add, '+') + 2;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (src_add[index_from_src_add] && i < size)
		dst[i++] = src_add[index_from_src_add++];
	dst[i] = '\0';
}
