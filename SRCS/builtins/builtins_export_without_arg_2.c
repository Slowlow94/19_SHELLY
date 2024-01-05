/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_without_arg_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:51:49 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 11:04:30 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	**add_var_to_export(char *var_to_add)
{
	char	**new;
	int		nbr_var;
	int		i;

	i = 0;
	nbr_var = 1;
	if (!(g_shell.export == NULL))
		nbr_var = ft_strlen_double_tab(g_shell.export) + 1;
	new = malloc(sizeof(char *) * (nbr_var + 1));
	if (!new)
		return (free_envp_export_new(new, "new"));
	while (g_shell.export && g_shell.export[i] && nbr_var > 1)
	{
		new[i] = cpy_second_tab_in_tab(g_shell.export[i]);
		if (!new[i])
			return (free_envp_export_new(new, "new"));
		i++;
	}
	new[i] = cpy_second_tab_in_tab(var_to_add);
	if (!new[i])
		return (free_envp_export_new(new, "new"));
	new[++i] = NULL;
	ft_free_2d_char(&g_shell.export);
	g_shell.export = NULL;
	return (new);
}

char	**concat_double_tab(int nbr_variables)
{
	char	**env;
	int		i[2];

	env = malloc(sizeof(char *) * (nbr_variables + 1));
	if (!env)
		return (free_envp_export_new(env, "env"));
	i[0] = 0;
	while (g_shell.my_env && g_shell.my_env[i[0]])
	{
		env[i[0]] = cpy_second_tab_in_tab(g_shell.my_env[i[0]]);
		if (!env[i[0]])
			return (free_envp_export_new(env, "env"));
		i[0]++;
	}
	i[1] = 0;
	while (g_shell.export && g_shell.export[i[1]])
	{
		env[i[0]] = cpy_second_tab_in_tab(g_shell.export[i[1]]);
		if (!env[i[0]])
			return (free_envp_export_new(env, "env"));
		i[0]++;
		i[1]++;
	}
	env[i[0]] = NULL;
	return (env);
}
