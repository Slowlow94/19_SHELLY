/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:59:58 by salowie           #+#    #+#             */
/*   Updated: 2023/11/17 10:35:03 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	**free_envp_export_new(char **env, int i, char *str)
{
	perror(str);
	ft_free_2d_char(env, i);
	ft_free_2d_char(g_shell.my_envp, ft_strlen_double_tab(g_shell.my_envp));
	ft_free_2d_char(g_shell.export, ft_strlen_double_tab(g_shell.export));
	return (NULL);
}

char	**free_envp_export(char *str)
{
	perror(str);
	ft_free_2d_char(g_shell.my_envp, ft_strlen_double_tab(g_shell.my_envp));
	ft_free_2d_char(g_shell.export, ft_strlen_double_tab(g_shell.export));
	return (NULL);
}

void	ft_free_and_set_null(int nbr_var, char **str)
{
	ft_free_2d_char(str, nbr_var);
	str = NULL;
}
