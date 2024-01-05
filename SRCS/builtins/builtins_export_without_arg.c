/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_without_arg.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:05:07 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 15:58:39 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static int	is_in_newstr(char *str_envp, char **env_in_order)
{
	int	i;

	i = 0;
	while (env_in_order[i])
	{
		if (ft_strcmp(env_in_order[i], str_envp) == 0)
			return (1);
		i++;
	}
	return (0);
}

static char	*cpy_quote(char *str_env, int size, size_t i)
{
	size_t	j;
	int		flag;
	char	*tmp;

	j = 0;
	flag = 0;
	tmp = malloc(sizeof(char) * size);
	if (!tmp)
		return (NULL);
	while (str_env[i])
	{
		if (str_env[i] == '=' && flag == 0)
		{
			flag = 1;
			tmp[j++] = str_env[i++];
			tmp[j++] = '"';
		}
		if (str_env[i] != '\0')
			tmp[j++] = str_env[i++];
	}
	if (j > i)
		tmp[j] = '"';
	tmp[++j] = '\0';
	return (tmp);
}

static void	put_in_str_in_order(char ***env_in_ord, char *to_write, int nbr_var)
{
	int	i;

	i = 0;
	while ((*env_in_ord)[i])
		i++;
	(*env_in_ord)[i] = malloc(sizeof(char) * (ft_strlen(to_write) + 1));
	if (!(*env_in_ord)[i])
		free_envp_export_new(*env_in_ord, "env_in_ord");
	ft_strlcpy((*env_in_ord)[i], to_write, ft_strlen(to_write) + 1);
	if (nbr_var >= 0)
		(*env_in_ord)[i + 1] = NULL;
}

static char	**sorted_by_alpha(char **envp, int nbr_variables)
{
	int		i;
	char	**env_in_order;
	char	*towrite;

	env_in_order = malloc(sizeof(char *) * (nbr_variables + 1));
	if (!env_in_order)
		return (free_envp_export("env_in_order"));
	ft_bzero(env_in_order, nbr_variables + 1);
	env_in_order[nbr_variables] = NULL;
	while (nbr_variables >= 0)
	{
		i = 0;
		towrite = NULL;
		while (envp[i])
		{
			if ((is_in_newstr(envp[i], env_in_order) == 0) && (towrite == NULL 
					|| ft_strncmp(towrite, envp[i], ft_strlen(envp[i])) > 0))
				towrite = envp[i];
			i++;
		}
		if (towrite)
			put_in_str_in_order(&env_in_order, towrite, nbr_variables);
		nbr_variables--;
	}
	return (env_in_order);
}

int	export_without_cmd(int nbr_variables)
{
	int		i;
	char	**env_and_exported_values;
	char	**env_in_order;
	char	*result;

	i = 0;
	nbr_variables += ft_strlen_double_tab(g_shell.export);
	env_and_exported_values = concat_double_tab(nbr_variables);
	if (!env_and_exported_values)
		return (1);
	env_in_order = sorted_by_alpha(env_and_exported_values, nbr_variables);
	if (!env_in_order)
		return (1);
	ft_free_2d_char(&env_and_exported_values);
	while (env_in_order && env_in_order[i])
	{
		result = cpy_quote((env_in_order[i]),
				ft_strlen(env_in_order[i]) + 3, 0);
		printf("declare -x ");
		printf("%s\n", result);
		ft_free((void **)&result);
		i++;
	}
	ft_free_2d_char(&env_in_order);
	return (0);
}
