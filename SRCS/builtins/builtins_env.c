/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:03:32 by salowie           #+#    #+#             */
/*   Updated: 2023/11/16 17:40:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_envp(char **argv, int i)
{
	int	j;

	j = 0;
	if (argv[i + 1])
		return (printf("%s: No such file or directory\n", argv[i + 1]));
	if (!g_shell.my_envp)
		g_shell.my_envp = NULL;
	while (g_shell.my_envp[j])
		printf("%s\n", g_shell.my_envp[j++]);
	return (0);
}
