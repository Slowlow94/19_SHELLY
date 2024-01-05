/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:40:57 by salowie           #+#    #+#             */
/*   Updated: 2024/01/02 16:46:49 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	is_builtins(char **argv)
{
	int	i;

	i = 0;
	if (!argv[0])
		return (-1);
	if (ft_strncmp(argv[i], "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "cd/", 3) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "env", 4) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "export", 7) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(argv[i], "unset", 6) == 0)
		return (1);
	else
		return (0);
}

int	exec_builtins(char **argv)
{
	int			i;

	i = 0;
	if (!argv[0])
		return (0);
	if (ft_strncmp(argv[i], "echo", 5) == 0)
		return (ft_echo(argv, i + 1));
	else if (ft_strncmp(argv[i], "cd", 3) == 0)
		return (ft_cd(argv[i + 1]));
	else if (ft_strncmp(argv[i], "cd/", 3) == 0)
		return (printf("%s: No such file or directory\n", argv[i]));
	else if (ft_strncmp(argv[i], "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(argv[i], "env", 4) == 0)
		return (ft_envp(argv, i));
	else if (ft_strncmp(argv[i], "export", 7) == 0)
		return (ft_export(argv, i + 1));
	else if (ft_strncmp(argv[i], "exit", 5) == 0)
		return (ft_exit(argv, i + 1, 0));
	else if (ft_strncmp(argv[i], "unset", 6) == 0)
		return (ft_unset(argv, i + 1, 0));
	else 
		return (-1);
	return (0);
}
