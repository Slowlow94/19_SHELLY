/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:02:33 by salowie           #+#    #+#             */
/*   Updated: 2023/11/02 11:35:58 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int	ft_cd(char *path)
{
	char	dir[PATH_MAX];

	if (!path || ft_strncmp(path, ".", 2) == 0)
		return (0);
	if (ft_strlen(path) > PATH_MAX)
		perror ("cd");
	else if (ft_strncmp(path, "-", 2) == 0)
	{
		if (getcwd(dir, sizeof(dir)) == NULL)
			perror("cd");
		else
		{
			// chdir(path); // aller chercher commande precedente
			printf("%s\n", dir);
		}
	}
	else if (chdir(path) == 0)
	{
		if (getcwd(dir, sizeof(dir)) == NULL)
			perror ("cd");
		else
			printf("The selected directory is: %s\n", dir); // test
		return (0);
	}
	else
		printf("cd: %s: No such file or directory\n", path);
	return (1);
}
