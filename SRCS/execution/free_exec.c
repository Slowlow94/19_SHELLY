/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:09:26 by salowie           #+#    #+#             */
/*   Updated: 2023/12/26 15:26:45 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_error_free_and_close(t_shell *shell, char *str)
{
	perror(str);
	ft_free_all(shell);
	exit (1);
}

void	free_rev_double_tab(t_pipe *pipex, int i)
{
	if (!pipex->fd)
		return ;
	while (i >= 0)
	{
		ft_free((void **)&pipex->fd[i]);
		i--;
	}
	ft_free((void **)&pipex->fd);
}
