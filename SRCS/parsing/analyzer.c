/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:21:39 by gvardaki          #+#    #+#             */
/*   Updated: 2023/12/28 13:35:55 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_analyze(char **cmd)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (!cmd)
		return (1);
	while (cmd[++i] && ret == 0)
	{
		if (cmd[i][0] == '<' && (cmd[i][1] == 0))
		{
			ret = ft_check_file(cmd[i + 1]);
		}
		else if (cmd[i][0] == '>')
		{
			ret = ft_check_outfile(cmd[i + 1]);
		}
		else if (cmd[i][0] == '.' && ft_isalnum(cmd[i][1]) == 1)
		{
			ret = ft_check_file(cmd[i]);
		}
	}
	return (ret);
}

int	ft_check_file(char *path)
{
	int			fd;

	if (!path || path[0] == '>' || path[0] == '&' || path[0] == '<')
	{
		if (!path)
			ft_printf("%s `%s'\n", SYNTAX, "newline");
		else
			ft_printf("%s `%c'\n", SYNTAX, path[0]);
		return (258);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("minishell: ");
		perror(path);
		g_shell.status = 1;
		return (1);
	}
	else 
	{
		close(fd);
		return (0);
	}
}

int	ft_check_outfile(char *path)
{
	int			fd;
	mode_t		mod;

	if (!path || path[0] == '>' || path[0] == '&' || path[0] == '<')
	{
		if (!path)
			ft_printf("%s `%s'\n", SYNTAX, "newline");
		else
			ft_printf("%s `%c'\n", SYNTAX, path[0]);
		return (258);
	}
	mod = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open(path, O_WRONLY | O_CREAT, mod);
	if (fd == -1)
	{
		ft_printf("minishell: ");
		perror(path);
		g_shell.status = 1;
		return (1);
	}
	else 
	{
		close(fd);
		return (0);
	}
}
