/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:05 by salowie           #+#    #+#             */
/*   Updated: 2023/11/06 10:55:22 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

// static int	until_equal(char *cmd)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd[i] != '=')
// 		i++;
// 	return (i + 1);
// }

static size_t	nbr_variables_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static int	is_in_new_str(char *str_envp, char **env_in_order)
{
	int	i;

	i = 0;
	while (env_in_order[i])
	{
		// if (ft_strncmp(str_envp, "_=", 2) == 0)
		// 	return (1);
		if (ft_strcmp(env_in_order[i], str_envp) == 0)
			return (1);
		i++;
	}
	return (0);
}

static char	*cpy_quote(char *str_env, int size)
{
	size_t	i;
	size_t	j;
	int		flag;
	char	*tmp;

	i = 0;
	j = 0;
	flag = 0;
	tmp = malloc(sizeof(char) * size);
	if (!tmp)
		return (NULL);
	while (str_env[i])
	{
		if (str_env[i] == '=' && flag == 0)
		{
			tmp[j++] = str_env[i++];
			tmp[j++] = '"';
			flag = 1;
		}
		else
			tmp[j++] = str_env[i++];
	}
	tmp[j++] = '"';
	tmp[j] = '\0';
	return (tmp);
}

static void	put_in_str_in_order(char ***env_in_order, char *first_to_write, int nbr_variables)
{
	int	i;

	i = 0;
	while ((*env_in_order)[i])
		i++;
	(*env_in_order)[i] = malloc(sizeof(char) * (ft_strlen(first_to_write) + 1));
	if (!(*env_in_order)[i])
	{
		perror ("malloc");
		return;
	}
	ft_strlcpy((*env_in_order)[i], first_to_write, ft_strlen(first_to_write) + 1);
	if (nbr_variables >= 0) // remettre = ?
		(*env_in_order)[i + 1] = NULL;
}

static char	**sorted_by_alpha(char **envp, int nbr_variables)
{
	int	i;
	char *first_to_write;
	char **env_in_order;

	env_in_order = malloc(sizeof(char *) * (nbr_variables + 1)); // enlever le + 1 ?
	if (!env_in_order)
		perror("malloc");
	ft_bzero(env_in_order, nbr_variables);
	env_in_order[nbr_variables] = NULL;
	while (nbr_variables >= 0)
	{
		i = 0;
		first_to_write = NULL;
		while (envp[i])
		{
			if (first_to_write == NULL || ft_strncmp(first_to_write, envp[i], ft_strlen(envp[i])) > 0)
			{
				if (is_in_new_str(envp[i], env_in_order) == 0)
					first_to_write = envp[i];
			}
			i++;
		}
		if (first_to_write)
			put_in_str_in_order(&env_in_order, first_to_write, nbr_variables);
		nbr_variables--;
	}
	return (env_in_order);
}

static int	export_without_cmd(char **envp)
{
	int	i;
	int	nbr_variables;
	char **env_in_order;
	char *result;

	i = 0;
	nbr_variables = nbr_variables_envp(envp);
	env_in_order = sorted_by_alpha(envp, nbr_variables);
	while (env_in_order[i])
	{
		result = cpy_quote((env_in_order[i]), ft_strlen(env_in_order[i]) + 3);
		printf("declare -x ");
		printf("%s\n", result);
		free(result);
		i++;
	}
	free_double_tab_char(env_in_order, nbr_variables);
	return (0);
}

int	ft_export(char **envp, char *cmd)
{
	// size_t	cpy_size;

	if (cmd == NULL)
		if (export_without_cmd(envp) == 1)
			return (1);
	// else
	// {
	// 	// if (check_cmd(cmd) == 1)
	// 	// 	return (0); // a voir s'il a plusieurs cas ?? 
	// 	cpy_size = until_equal(cmd);
	// 	if (!cpy_size)
	// 		return (1);
	// 	// char name_cmd[cpy_size + 1];
	// }
	return (0);
}
