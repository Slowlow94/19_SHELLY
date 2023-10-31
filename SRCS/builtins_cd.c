/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:02:33 by salowie           #+#    #+#             */
/*   Updated: 2023/10/31 09:48:32 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	ft_cd(char *path)
{
	char	dir[PATH_MAX];
	
	if (chdir(path) == 0)
	{
		printf("The selected directory is: %s\n", getcwd(dir, sizeof(dir))); // test
		return (0);
	}
	else
		perror(path);
	return (1);
}
