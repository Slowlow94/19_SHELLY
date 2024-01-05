/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:30:57 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 13:21:06 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static void	ft_get_final_command(char **div, char ***fin);
static void	ft_in_out(char **div, char **in, char **out, char **rep);
static void	ft_wich_is_cmd_in_out(char **div_cmd);

void	ft_div_tab(void)
{
	char	**div_cmd;
	int		i;

	i = 0;
	while (i < (g_shell.pipex.pipe_nbr + 1))
	{
		div_cmd = ft_split_quote(g_shell.cmds_redir[i], 32);
		if (!div_cmd)
		{
			perror("div_cmd");
			ft_free_all(&g_shell);
			exit (1);
		}
		ft_wich_is_cmd_in_out(div_cmd);
		ft_free_2d_char(&div_cmd);
		i++;
	}
}

static void	ft_wich_is_cmd_in_out(char **div_cmd)
{
	char	*input;
	char	*output;
	char	*output_replace;
	char	**final_cmds;

	input = NULL;
	output = NULL;
	output_replace = NULL;
	final_cmds = NULL;
	ft_in_out(div_cmd, &input, &output, &output_replace);
	ft_get_final_command(div_cmd, &final_cmds);
	if (ft_add_to_linked_list(input, output, output_replace, final_cmds) == 1)
	{
		ft_free_2d_char(&div_cmd);
		ft_free_all(&g_shell);
		exit (1);
	}
}

static void	ft_in_out(char **div, char **in, char **out, char **rep)
{
	int	i;

	i = 0;
	while (div[i])
	{
		if (ft_strncmp(div[i], "<", 2) == 0 
			|| ft_strncmp(div[i], "<<", 3) == 0)
			*in = div[++i];
		else if (ft_strncmp(div[i], ">", 2) == 0)
		{
			if (*rep)
				*rep = NULL;
			*out = div[++i];
		}
		else if (ft_strncmp(div[i], ">>", 3) == 0)
		{
			if (*out)
				*out = NULL;
			*rep = div[++i];
		}
		i++;
	}
}

static void	ft_get_final_command(char **div, char ***fin)
{
	int	i;

	i = 0;
	while (div[i])
	{
		if (!*fin)
		{
			*fin = ft_argv_cmd(&div[i], 0);
			if (!*fin)
			{
				ft_free_2d_char(&div);
				ft_free_all(&g_shell);
				exit(1);
			}
			return ;
		}
		i++;
	}
}
