/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:34:17 by salowie           #+#    #+#             */
/*   Updated: 2023/11/16 17:36:07 by salowie          ###   ########.fr       */
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
		return (NULL); // free !!
	while (i < nbr_var)
	{
		if (!(ft_strncmp(e[i], var, until(var, '=')) == 0 
				&& e[i][until(var, '=')] == '='))
		{
			printf("%s\n", e[i]);
			new[j] = cpy_second_tab_in_tab(e[i]);
			new[j + 1] = NULL;
			j++;
		}
		i++;
	}
	ft_free_2d_char(e, nbr_var);
	return (new);
}

int	ft_unset(char **var, int i)
{
	if (var[i] == NULL)
		return (0);
	while (var[i])
	{
		if (is_special_caracter(var[i]) == 1 || is_char(var[i], '=') == 1)
		{
			printf(" unset: '%s' : not a valid identifier\n", var[i]);
			break ;
		}
		if (g_shell.export != NULL)
		{
			if (is_already_in_export(g_shell.export, var[i]) == 1)
				g_shell.export = del_var_export(g_shell.export, var[i]);
		}
		if (is_non_var_in_env(g_shell.my_envp, var[i]) == 1)
		{
			g_shell.my_envp = del_var_env_unset(g_shell.my_envp, var[i]);
		}
		i++;
	}
	return (0);
}

