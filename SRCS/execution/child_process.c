/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:47:10 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 15:33:54 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static void	first_pipe(t_pipe pipex, int i, t_lst *list);
static void	middle_pipe(t_pipe pipex, int i, t_lst *list);
static void	last_pipe(t_pipe pipex, int i, t_lst *list);

void	child_process(t_pipe pipex, int i, t_lst *list)
{
	int	res_builtins;

	ft_signal();
	g_shell.child = true;
	res_builtins = 0;
	if (i == 0)
		first_pipe(pipex, i, list);
	else if (i == pipex.pipe_nbr)
		last_pipe(pipex, i, list);
	else
		middle_pipe(pipex, i, list);
	close_all_pipe(&pipex);
	if (list->cmd)
		res_builtins = exec_builtins(list->cmd);
	if (res_builtins == -1 && list->cmd)
	{
		parsing_path(&pipex, list->cmd);
		check_cmd(pipex);
	}
	else if (res_builtins == 1)
		g_shell.pipex.status = 1;
}

static void	first_pipe(t_pipe pipex, int i, t_lst *list)
{
	if (list->infile == NULL && list->outfile == NULL 
		&& list->out_replace == NULL)
	{
		if (dup2(pipex.fd[i][1], STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "INFILE dup2 failed");
	}
	else if (list->infile && list->outfile == NULL 
		&& list->out_replace == NULL)
	{
		if (dup2(pipex.in, STDIN_FILENO) < 0 
			|| dup2(pipex.fd[i][1], STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "INFILE dup2 failed");
	}
	else if (list->infile == NULL && (list->outfile || list->out_replace))
	{
		if (dup2(pipex.out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile && (list->outfile || list->out_replace))
	{
		if (dup2(pipex.in, STDIN_FILENO) < 0 
			|| dup2(pipex.out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
}

static void	middle_pipe(t_pipe pipex, int i, t_lst *list)
{
	if (list->infile == NULL && list->outfile == NULL 
		&& list->out_replace == NULL)
	{
		if (dup2(pipex.fd[i - 1][0], STDIN_FILENO) < 0 
			|| dup2(pipex.fd[i][1], STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile && list->outfile == NULL && list->out_replace == NULL)
	{
		if (dup2(pipex.in, STDIN_FILENO) < 0 
			|| dup2(pipex.fd[i][1], STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile == NULL && (list->outfile || list->out_replace))
	{
		if (dup2(pipex.fd[i - 1][0], STDIN_FILENO) < 0 
			|| dup2(pipex.out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile && (list->outfile || list->out_replace))
	{
		if (dup2(pipex.in, STDIN_FILENO) < 0 
			|| dup2(pipex.out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
}

static void	last_pipe(t_pipe pipex, int i, t_lst *list)
{
	if (list->infile == NULL && list->outfile == NULL 
		&& list->out_replace == NULL)
	{
		if (dup2(pipex.fd[i - 1][0], STDIN_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile && list->outfile == NULL && list->out_replace == NULL)
	{
		if (dup2(pipex.in, STDIN_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile == NULL && (list->outfile || list->out_replace)) 
	{
		if (dup2(pipex.fd[i - 1][0], STDIN_FILENO) < 0 
			|| dup2(pipex.out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
	else if (list->infile && (list->outfile || list->out_replace))
	{
		if (dup2(pipex.in, STDIN_FILENO) < 0 
			|| dup2(pipex.out, STDOUT_FILENO) < 0)
			ft_error_free_and_close(&g_shell, "dup2 failed");
	}
}

void	close_all_pipe(t_pipe *pipex)
{
	int	i;

	i = 0;
	if (pipex->out)
		close(pipex->out);
	if (pipex->in)
		close(pipex->in);
	while (i < pipex->pipe_nbr)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		i++;
	}
}
