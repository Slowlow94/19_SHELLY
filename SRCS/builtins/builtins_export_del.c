/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export_del.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:46:44 by salowie           #+#    #+#             */
/*   Updated: 2023/11/17 11:34:25 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	*cpy_second_tab_in_tab(char *e)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(e) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, e, ft_strlen(e) + 1);
	return (new);
}

static char	**create_db_tab(int nbr_var, char *var, char **e)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * nbr_var);
	if (!new)
		return (NULL); // free !!
	while (i < nbr_var)
	{
		if (!(ft_strncmp(e[i], var, until(var, '=')) == 0 
				&& e[i][until(var, '=')] == '\0'))
		{
			new[j] = cpy_second_tab_in_tab(e[i]);
			if (!new[j])
				return (free_envp_export_new(new, j, "new"));
			new[j + 1] = NULL;
			j++;
		}
		i++;
	}
	return (new);
}

char	**del_var_export(char **e, char *var)
{
	int		nbr_var;
	char	**new;

	nbr_var = ft_strlen_double_tab(e);
	new = NULL;
	if (nbr_var == 1)
		ft_free_and_set_null(nbr_var, e);
	else
	{
		new = create_db_tab(nbr_var, var, e);
		if (!new)
			return (NULL);
		ft_free_2d_char(e, nbr_var);
	}
	return (new);
}

char	**del_var_env(char **e, char *var)
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
		return (free_envp_export("new"));
	while (i < nbr_var)
	{
		if (!(ft_strncmp(e[i], var, until(var, '=')) == 0 
				&& e[i][until(var, '=') + 1] == '\0'))
		{
			new[j] = cpy_second_tab_in_tab(e[i]);
			if (!new[j])
				return (free_envp_export_new(new, j, "new"));
			new[j + 1] = NULL;
			j++;
		}
		i++;
	}
	ft_free_2d_char(e, nbr_var);
	return (new);
}
