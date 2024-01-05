/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:23:30 by salowie           #+#    #+#             */
/*   Updated: 2024/01/03 17:04:02 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	no_pipe(t_lst *list)
{
	pid_t	pid;
	int		status;

	g_shell.child = true;
	pid = fork();
	if (pid == -1)
		ft_error_free_and_close(&g_shell, "Fork failed :");
	else if (pid == 0) 
	{
		ft_get_file_descriptors(&g_shell.pipex, list);
		in_out_no_pipe(list, &g_shell.pipex);
		if (list->cmd)
		{
			parsing_path(&g_shell.pipex, list->cmd);
			check_cmd(g_shell.pipex);
		}
		exit (g_shell.pipex.status);
	}
	else
	{
		close_all_pipe(&g_shell.pipex);
		waitpid(-1, &g_shell.pipex.status, 0);
		status = WEXITSTATUS(g_shell.pipex.status);
		g_shell.status = status;
	}
}

void	in_out_no_pipe(t_lst *list, t_pipe *pipex)
{
	if (list && list->infile)
	{
		if (dup2(pipex->in, STDIN_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
		close(pipex->in);
	}
	if (list && (list->outfile || list->out_replace))
	{
		if (dup2(pipex->out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
		close(pipex->out);
	}
}

void	ft_get_file_descriptors(t_pipe *pipex, t_lst *list)
{
	if (list && list->infile)
	{
		pipex->in = open(list->infile, O_RDONLY);
		if (pipex->in < 0)
		{
			perror("open if infile exist");
			ft_free_all(&g_shell);
			exit (1);
		}
	}
	ft_get_file_descriptors_out(pipex, list);
}

void	ft_get_file_descriptors_out(t_pipe *pipex, t_lst *list)
{
	if (list && list->outfile)
	{
		pipex->out = open(list->outfile, O_RDWR | O_TRUNC, 0644);
		if (pipex->out < 0)
		{
			perror("open if outfile exist");
			ft_free_all(&g_shell);
			exit (1);
		}
	}
	if (list && list->out_replace)
	{
		if (list->outfile)
			close (pipex->out);
		pipex->out = open(list->out_replace, O_WRONLY | O_APPEND, 0644);
		if (pipex->out < 0)
		{
			perror("open if outfile_replace exist");
			ft_free_all(&g_shell);
			exit (1);
		}
	}
}
