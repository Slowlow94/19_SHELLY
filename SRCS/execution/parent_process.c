/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:46:57 by salowie           #+#    #+#             */
/*   Updated: 2023/12/27 15:57:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	check_status(t_pipe pipex, int *statuses)
{
	int	i;

	i = 0;
	while (i < pipex.pipe_nbr)
	{
		if (statuses[i])
			g_shell.status = statuses[i];
		i++;
	}
}

void	parent_process(t_pipe pipex, pid_t pid)
{
	int	i;
	int	*statuses;

	i = 0;
	(void) pid;
	close_all_pipe(&pipex);
	statuses = (int *)malloc(sizeof(int) * (pipex.pipe_nbr + 1));
	if (!statuses)
	{
		free (statuses);
		ft_error_free_and_close(&g_shell, "statuses");
	}
	while (i <= pipex.pipe_nbr)
	{
		waitpid(-1, &pipex.status, 0);
		statuses[i] = WEXITSTATUS(pipex.status);
		i++;
	}
	check_status(pipex, statuses);
	free((void **)statuses);
}
