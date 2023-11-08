/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:03:32 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 18:19:06 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	ft_envp(char **my_envp, char **argv, int i)
{
	int	j;

	j = 0;
	if (argv[i + 1])
		return (printf("%s: No such file or directory\n", argv[i + 1]));
	while (my_envp[j])
		printf("%s\n", my_envp[j++]);
	return (0);
}
