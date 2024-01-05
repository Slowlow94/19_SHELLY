/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:59 by Sarah             #+#    #+#             */
/*   Updated: 2024/01/04 15:33:57 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_process(void)
{
	signal(SIGQUIT, ft_quit_handler);
	g_shell.pipex.decomp_cmd = NULL;
	g_shell.pipex.decomp_path = NULL;
	ft_div_tab();
	if (g_shell.pipex.pipe_nbr > 0)
		wich_process(g_shell.elem_to_pipe);
	else if (g_shell.pipex.pipe_nbr == 0
		&& is_builtins(g_shell.elem_to_pipe->cmd) == 1)
		no_pipe_builtins(g_shell.elem_to_pipe);
	else if (g_shell.pipex.pipe_nbr == 0
		&& is_builtins(g_shell.elem_to_pipe->cmd) == 0)
		no_pipe(g_shell.elem_to_pipe);
}

void	no_pipe_builtins(t_lst *list)
{
	int	res;
	int	stdout;
	int	stdin;

	stdout = dup(STDOUT_FILENO);
	stdin = dup(STDIN_FILENO);
	ft_get_file_descriptors(&g_shell.pipex, list);
	in_out_no_pipe(list, &g_shell.pipex);
	res = exec_builtins(list->cmd);
	if (dup2(stdin, STDIN_FILENO) < 0)
		ft_error_free_and_close(&g_shell, "dup2 failed");
	if (dup2(stdout, STDOUT_FILENO) < 0)
		ft_error_free_and_close(&g_shell, "dup2 failed");
	close_all_pipe(&g_shell.pipex);
	if (res == 1)
		g_shell.status = 1;
	if (res == 0)
		g_shell.status = 0;
}

void	wich_process(t_lst *list)
{
	pid_t	pid;
	int		i;

	i = 0;
	is_creating_pipe_ok();
	while (list)
	{
		pid = fork();
		if (pid == -1)
			ft_error_free_and_close(&g_shell, "Fork failed :");
		if (pid == 0)
		{
			ft_get_file_descriptors(&g_shell.pipex, list);
			child_process(g_shell.pipex, i, list);
			ft_free_struct(&g_shell.pipex);
			exit (g_shell.pipex.status);
		}
		list = list->next;
		i++;
	}
	parent_process(g_shell.pipex, pid);
}

void	is_creating_pipe_ok(void)
{
	if (create_pipe(&g_shell.pipex, g_shell.pipex.pipe_nbr) == 1)
	{
		ft_free_all(&g_shell);
		exit(1);
	}
}

int	create_pipe(t_pipe *pipex, int nbr_pipe)
{
	int	i;

	i = 0;
	pipex->fd = malloc(sizeof(int *) * (nbr_pipe + 1));
	if (!pipex->fd)
	{
		ft_free((void **)&pipex->fd);
		return (1);
	}
	while (i < nbr_pipe)
	{
		pipex->fd[i] = malloc(sizeof(int) * 2);
		if (!pipex->fd[i] || pipe(pipex->fd[i]) == -1)
		{
			if (!pipex->fd[i])
				perror("Malloc for pipe failed");
			else
				perror("Pipe failed");
			free_rev_double_tab(pipex, i);
			return (1);
		}
		i++;
	}
	pipex->fd[i] = NULL;
	return (0);
}
