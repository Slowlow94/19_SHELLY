/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_in_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:36:07 by salowie           #+#    #+#             */
/*   Updated: 2023/11/17 11:57:56 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	**add_new_to_env(char **envp, char *var, int nbr_variables)
{
	int		i;
	char	**new_envp;

	i = 0;
	new_envp = malloc(sizeof(char *) * (nbr_variables + 2));
	if (!new_envp)
		return (free_envp_export("new_envp"));
	while (envp[i])
	{
		new_envp[i] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		if (!new_envp[i])
			return (free_envp_export_new(new_envp, i, "new_envp"));
		ft_strlcpy(new_envp[i], envp[i], ft_strlen(envp[i]) + 1);
		new_envp[i + 1] = NULL;
		i++;
	}
	new_envp[i] = malloc(sizeof(char) * (ft_strlen(var) + 1));
	if (!new_envp[i])
		return (free_envp_export_new(new_envp, i, "new_envp"));
	ft_strlcpy_whithout_plus(new_envp[i], var, ft_strlen(var) + 1);
	new_envp[++i] = NULL;
	ft_free_2d_char(envp, nbr_variables);
	return (new_envp);
}

char	**add_to_var_in_env(char **envp, char *var)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_strlen_from(var, until(var, '+') + 1);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, until(var, '+')) == 0)
		{
			size += ft_strlen(envp[i]) - 1;
			tmp = ft_strdup(envp[i]);
			free(envp[i]);
			envp[i] = malloc (sizeof(char) * (size + 1));
			if (!envp[i])
				return (free_envp_export_new(envp, i, "envp"));
			cpy_for_add_var(envp[i], var, tmp, size);
			free(tmp);
		}
		i++;
	}
	return (envp);
}

char	**replace_var_in_env(char *var)
{
	int		size;
	int		i;

	i = 0;
	while (g_shell.my_envp[i])
	{
		if (ft_strncmp(g_shell.my_envp[i], var, until(var, '=')) == 0)
		{
			size = ft_strlen(var);
			free(g_shell.my_envp[i]);
			g_shell.my_envp[i] = malloc (sizeof(char) * (size + 1));
			if (!g_shell.my_envp[i])
				return (free_envp_export(g_shell.my_envp[i]));
			ft_strlcpy(g_shell.my_envp[i], var, size + 1);
		}
		i++;
	}
	return (g_shell.my_envp);
}
