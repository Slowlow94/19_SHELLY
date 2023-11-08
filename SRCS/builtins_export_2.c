/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:51:38 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 18:15:29 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	is_var_exists(char **envp, char *var)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, until_plus(var, '+')) == 0 
			|| ft_strncmp(envp[i], var, until_plus(var, '=')) == 0)
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

int	until_plus(char *var, char c)
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

	i = 0;
	if (!src)
		return ;
	if (size != 0)
	{
		while (src[i] && i < size -1)
		{
			if (src[i] == '+')
				i++;
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

void	cpy_for_add_var(char *dst, char *src_add, char *src, int size)
{
	int	i;
	int	index_from_src_add;

	i = 0;
	index_from_src_add = until_plus(src_add, '+') + 2;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (src_add[index_from_src_add] && i < size)
		dst[i++] = src_add[index_from_src_add++];
	dst[i] = '\0';
}
