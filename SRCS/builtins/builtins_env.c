/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:03:32 by salowie           #+#    #+#             */
/*   Updated: 2023/11/27 10:53:49 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_envp(char **argv, int i)
{
	int	j;

	j = 0;
	if (argv[i + 1])
		return (printf("%s: No such file or directory\n", argv[i + 1]));
	if (!g_shell.my_env)
		g_shell.my_env = NULL;
	while (g_shell.my_env[j])
		printf("%s\n", g_shell.my_env[j++]);
	return (0);
}
