/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:28:42 by salowie           #+#    #+#             */
/*   Updated: 2023/11/13 11:01:45 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/minishell.h"

char	**create_my_envp(char **envp)
{
	int		i;
	int		nbr_variables;
	char	**my_envp;

	i = 0;
	nbr_variables = ft_strlen_double_tab(envp);
	my_envp = malloc(sizeof(char *) * (nbr_variables + 1));
	if (!my_envp)
		return (NULL);
	while (envp[i])
	{
		my_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	my_envp[i] = NULL;
	return (my_envp);
}
