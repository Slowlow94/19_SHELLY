/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:08:47 by salowie           #+#    #+#             */
/*   Updated: 2023/12/15 12:42:21 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	**free_envp_export_new(char **env, char *str)
{
	perror(str);
	ft_free_2d_char(&env);
	ft_free_2d_char(&g_shell.my_env);
	ft_free_2d_char(&g_shell.export);
	return (NULL);
}

char	**free_envp_export(char *str)
{
	perror(str);
	ft_free_2d_char(&g_shell.my_env);
	ft_free_2d_char(&g_shell.export);
	return (NULL);
}

void	ft_free_and_set_null(char **str)
{
	ft_free_2d_char(&str);
	str = NULL;
}
