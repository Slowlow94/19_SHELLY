/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:05 by salowie           #+#    #+#             */
/*   Updated: 2023/11/17 12:04:34 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static int	ft_is_plus_equal(char *var, int nbr_var)
{
	if (is_var_exists(g_shell.my_envp, var) == 1)
	{
		g_shell.my_envp = add_to_var_in_env(g_shell.my_envp, var);
		if (!g_shell.my_envp)
			return (1);
	}
	if (is_var_exists(g_shell.my_envp, var) == 0)
	{
		g_shell.my_envp = add_new_to_env(g_shell.my_envp, var, nbr_var);
		if (!g_shell.my_envp)
			return (1);
	}
	if (is_already_in_export(g_shell.export, var) == 1)
	{
		g_shell.export = del_var_export(g_shell.export, var);
		if (!g_shell.export)
			return (1);
	}
	return (0);
}

static int	ft_is_equal(char *var, int nbr_var)
{
	if (is_var_exists(g_shell.my_envp, var) == 1)
	{
		g_shell.my_envp = replace_var_in_env(var);
		if (!g_shell.my_envp)
			return (1);
	}
	if (is_var_exists(g_shell.my_envp, var) == 0)
	{
		g_shell.my_envp = add_new_to_env(g_shell.my_envp, var, nbr_var);
		if (!g_shell.my_envp)
			return (1);
	}
	if (is_already_in_export(g_shell.export, var) == 1)
	{
		g_shell.export = del_var_export(g_shell.export, var);
		if (!g_shell.export)
			return (1);
	}
	return (0);
}

static int	what_to_do_for_var(char *var, int nbr_var)
{
	if (is_equal_str(var, "+=") == 1)
	{
		if (ft_is_plus_equal(var, nbr_var) == 1)
			return (1);
	}
	if (is_char(var, '=') == 1)
		ft_is_equal(var, nbr_var);
	else
	{
		if (is_non_var_in_env(g_shell.my_envp, var) == 0)
		{
			g_shell.export = add_var_to_export(var);
			if (!g_shell.export)
				return (1);
		}
	}
	return (0);
}

int	ft_export(char **var, int i)
{
	int	nbr_variables;

	nbr_variables = ft_strlen_double_tab(g_shell.my_envp);
	if (var[i] == NULL)
	{
		if (export_without_cmd(nbr_variables) == 1)
			return (1); // msg d'error comme celui ci dessous ?
	}
	while (var[i])
	{
		if (is_special_caracter(var[i]) == 0)
		{
			if (what_to_do_for_var(var[i], nbr_variables) == 1)
				return (1);
		}
		else
			printf(" export: '%s' : not a valid identifier\n", var[i]);
		i++;
	}
	return (0);
}
