/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:49 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 15:55:55 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/minishell.h"

static char	*ft_incr_shlvl(char *str);

char	**create_my_envp(char **envp)
{
	int		i;
	int		nbr_variables;
	char	**my_envp;

	i = 0;
	g_shell.env = true;
	nbr_variables = ft_strlen_double_tab(envp);
	my_envp = malloc(sizeof(char *) * (nbr_variables + 1));
	if (!my_envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "SHLVL", 5) == 0)
		{
			my_envp[i] = ft_incr_shlvl(envp[i]);
			i++;
			continue ;
		}
		my_envp[i] = ft_strdup(envp[i]);
		if (!my_envp[i])
			return (NULL);
		i++;
	}
	my_envp[i] = NULL;
	return (my_envp);
}

static char	*ft_incr_shlvl(char *str)
{
	char	*ret;
	char	*tmp;
	char	*a;
	char	**split;
	int		lvl;

	tmp = ft_strdup("SHLVL=");
	if (!tmp)
		return (NULL);
	split = ft_split(str, '=');
	if (!split)
		return (NULL);
	lvl = ft_atoi(split[1]);
	++lvl;
	a = ft_itoa(lvl);
	ret = ft_strjoin(tmp, a);
	if (!ret)
		return (NULL);
	free(a);
	free(tmp);
	ft_free_2d(split);
	return (ret);
}

int	ft_strlen_double_tab(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}
