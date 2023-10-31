/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:05 by salowie           #+#    #+#             */
/*   Updated: 2023/10/31 10:27:10 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

static int	until_equal(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '=')
		i++;
	return (i + 1);
}

static size_t	nbr_variables_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static int	is_in_new_str(char *str_envp, char **str_in_order)
{
	int	i;

	i = 0;
	while (str_in_order[i])
	{
		if (ft_strcmp(str_in_order[i], str_envp) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	sorted_by_alpha(char **envp, size_t	nbr_variables)
{
	int	i;
	char *first_to_write;
	char *str_in_order[nbr_variables + 1];

	i = 0;
	first_to_write = NULL;
	while (envp[i])
	{
		if (ft_isalpha(envp[i][0]) == 1) // attention aux variables qui ne commencent pas avec alpha
			if (ft_strcmp(first_to_write, envp[i]) > 0)
			{
				if (is_in_new_str(envp[i], str_in_order) == 1) // si ca ne l'est pas ok
					first_to_write = envp[i];
			}
		i++;
	}
	put_in_str_in_order(**str_in_order, *first_to_write);
	i = 0;
	
}

static int	export_without_cmd(char **envp)
{
	int	i;
	size_t	nbr_variables;

	i = 0;
	nbr_variables = nbr_variables_envp(envp);
	while (nbr_variables)
	{
		sorted_by_alpha(envp, nbr_variables);
		nbr_variables--;
	}
	return (0);
}

int	ft_export(char **envp, char *cmd)
{
	size_t	cpy_size;

	if (cmd == NULL)
		export_without_cmd(envp);
	else
	{
		// if (check_cmd(cmd) == 1)
		// 	return (0); // a voir s'il a plusieurs cas ?? 
		cpy_size = until_equal(cmd);
		if (!cpy_size)
			return (1);
		// char name_cmd[cpy_size + 1];
	}
	return (0);
}
