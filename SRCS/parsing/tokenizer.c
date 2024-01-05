/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:48:42 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/02 16:53:44 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static int	ft_add_pipe(char *cmd, int *i)
{
	t_list	*node;

	node = malloc(sizeof (t_list));
	if (!node)
		return (1);
	node->content = NULL;
	node->pipe = cmd[*i];
	node->next = NULL;
	ft_lstadd_back(&g_shell.token_list, node);
	g_shell.pipex.pipe_nbr++;
	*i += 1;
	return (0);
}

static	bool	ft_is_skip(char c)
{
	if (c == 32 || c == 92 || c == ';')
		return (true);
	else
		return (false);
}

void	ft_error_list(t_list **lst, int err)
{
	ft_lstclear(lst, free);
	free(g_shell.cmd_line);
	ft_free_matrix(g_shell.my_env);
	if (err == 1)
	{
		perror("memory allocation failed");
		exit(3);
	}
}

static int	ft_add_path(char *cmd, int *i, int len)
{
	char	*wd;
	char	*file;
	char	*str;

	wd = NULL;
	file = NULL;
	wd = getcwd(wd, 0);
	while (cmd[len] && cmd[len] != 32 && cmd[len] != '|')
		len++;
	*i += len;
	file = ft_substr(cmd, 1, len);
	if (!file)
		return (1);
	str = ft_strjoin(wd, file);
	free(wd);
	free(file);
	if (!str)
		return (1);
	ft_lstadd_back(&g_shell.token_list, ft_lstnew(str));
	return (0);
}

void	ft_tokenizer(char *cmd, char **env, int i)
{
	int	ret;

	ret = 0;
	while (cmd[i])
	{
		if (ft_is_skip(cmd[i]))
			i++;
		else if (cmd[i] == '|')
			ret = ft_add_pipe(cmd, &i);
		else if (cmd[i] == '<' || cmd [i] == '>')
			ret = ft_add_ope(cmd, &i);
		else if (cmd[i] == 39)
			ret = ft_add_str(cmd, &i);
		else if (cmd[i] == 34)
			ret = ft_add_str_var(cmd, &i, env);
		else if (cmd[i] == '.' && cmd[i + 1] == '/')
			ret = ft_add_path(&cmd[i], &i, 0);
		else
			ret = ft_add_token(cmd, &i, 0);
		if (ret != 0)
			ft_error_list(&g_shell.token_list, ret);
	}
}
