/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:34:12 by salowie           #+#    #+#             */
/*   Updated: 2024/01/03 17:04:43 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_free(void **value)
{
	if (*value)
	{
		free(*value);
		*value = NULL;
	}
}

void	ft_free_2d_int(int ***fd)
{
	int	**pt_fd;
	int	i;

	pt_fd = *fd;
	i = 0;
	if (!pt_fd)
		return ;
	while (pt_fd[i] && i <= g_shell.pipex.pipe_nbr)
	{
		ft_free((void **)&pt_fd[i]);
		i++;
	}
	free(*fd);
	*fd = NULL;
}

void	ft_free_2d_char(char ***str_ptr)
{
	char	**str;
	int		i;

	i = 0;
	str = *str_ptr;
	if (!str)
		return ;
	while (str && str[i])
	{
		ft_free((void **)&str[i]);
		i++;
	}
	free(*str_ptr);
	*str_ptr = NULL;
}

void	ft_free_struct(t_pipe *pipex)
{
	if (!pipex)
		return ;
	if (pipex->in)
		close (pipex->in);
	if (pipex->out)
		close (pipex->out);
	if (pipex->decomp_cmd)
		ft_free_2d_char(&pipex->decomp_cmd);
	if (pipex->decomp_path)
		ft_free_2d_char(&pipex->decomp_path);
}

void	ft_free_all(t_shell *shell)
{
	if (!shell)
		return ;
	ft_free_struct(&shell->pipex);
	if (shell->cmds_redir)
		ft_free_2d_char(&shell->cmds_redir);
	if (shell->elem_to_pipe)
		ft_lc_clear(&shell->elem_to_pipe);
	if (shell->export)
		ft_free_2d_char(&shell->export);
	if (shell->my_env)
		ft_free_2d_char(&shell->my_env);
}
