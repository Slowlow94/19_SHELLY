/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:34:17 by salowie           #+#    #+#             */
/*   Updated: 2023/12/28 11:04:31 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	**del_var_env_unset(char **e, char *var)
{
	int		nbr_var;
	int		i;
	int		j;
	char	**new;

	nbr_var = ft_strlen_double_tab(e);
	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * nbr_var);
	if (!new)
		return (NULL);
	while (i < nbr_var)
	{
		if (!(ft_strncmp(e[i], var, until(var, '=')) == 0 
				&& e[i][until(var, '=')] == '='))
		{
			new[j] = cpy_second_tab_in_tab(e[i]);
			new[j + 1] = NULL;
			j++;
		}
		i++;
	}
	ft_free_2d_char(&e);
	return (new);
}

int	ft_unset(char **var, int i, int res)
{
	if (var[i] == NULL)
		return (0);
	while (var[i])
	{
		if (is_special_caracter(var[i]) == 1 || is_char(var[i], '=') == 1)
		{
			printf(" unset: '%s' : not a valid identifier\n", var[i]);
			res = 1;
			break ;
		}
		if (g_shell.export != NULL)
		{
			if (is_already_in_export(g_shell.export, var[i]) == 1)
				g_shell.export = del_var_export(g_shell.export, var[i]);
		}
		if (is_non_var_in_env(g_shell.my_env, var[i]) == 1)
		{
			g_shell.my_env = del_var_env_unset(g_shell.my_env, var[i]);
			if (!g_shell.my_env)
				ft_error_free_and_close(&g_shell, "g_shell.my_env");
		}
		i++;
	}
	return (res);
}
