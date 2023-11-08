/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:05 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 18:17:54 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

static char	**add_new_var_to_env(char **envp, char *var, int nbr_variables)
{
	int		i;
	char	**new_envp;

	i = 0;
	new_envp = malloc(sizeof(char *) * (nbr_variables + 2));
	if (!new_envp)
		return (NULL);
	while (envp[i])
	{
		new_envp[i] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		if (!new_envp[i])
			return (NULL);
		ft_strlcpy(new_envp[i], envp[i], ft_strlen(envp[i]) + 1);
		new_envp[i + 1] = NULL;
		i++;
	}
	new_envp[i] = malloc(sizeof(char) * (ft_strlen(var) + 1));
	if (!new_envp[i])
		return (NULL);
	ft_strlcpy_whithout_plus(new_envp[i], var, ft_strlen(var) + 1);
	new_envp[++i] = NULL;
	free_double_tab_char(envp, nbr_variables);
	return (new_envp);
}

static char	**add_to_var_in_env(char **envp, char *var)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_strlen_from(var, until_plus(var, '+') + 1);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, until_plus(var, '+')) == 0)
		{
			size += ft_strlen(envp[i]) - 1;
			tmp = ft_strdup(envp[i]);
			free(envp[i]);
			envp[i] = malloc (sizeof(char) * (size + 1));
			if (!envp[i])
				return (NULL);
			cpy_for_add_var(envp[i], var, tmp, size);
			free(tmp);
		}
		i++;
	}
	return (envp);
}

static char	**replace_var_in_env(char **envp, char *var)
{
	int		size;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, until_plus(var, '=')) == 0)
		{
			size = ft_strlen(var);
			free(envp[i]);
			envp[i] = malloc (sizeof(char) * (size + 1));
			if (!envp[i])
				return (NULL);
			ft_strlcpy(envp[i], var, size + 1);
		}
		i++;
	}
	return (envp);
}

int	ft_export(char **envp, char *var)
{
	int		i;
	int		nbr_variables;
	char	**my_new_env;

	i = 0;
	my_new_env = NULL;
	nbr_variables = nbr_variables_envp(envp);
	if (var == NULL)
	{
		if (export_without_cmd(envp, nbr_variables) == 1)
			return (1); // msg d'error comme celui ci dessous ?
	}
	else
	{
		if (is_var_exists(envp, var) == 1 && ft_isalpha(var[0]) == 1) // VAR EXIST
		{
			if (is_equal_str(var, "+=") == 1)
				my_new_env = add_to_var_in_env(envp, var);
			else if (is_equal(var, '=') == 1)
				my_new_env = replace_var_in_env(envp, var);
		}
		else if (is_var_exists(envp, var) == 0 && ft_isalpha(var[0]) == 1) // VAR DOESN'T EXIST
		{
			printf("test3\n");
			my_new_env = add_new_var_to_env(envp, var, nbr_variables);
		}
		else
			printf(" export: '%s' : not a valid identifer", var);
	}
	return (0);
}
