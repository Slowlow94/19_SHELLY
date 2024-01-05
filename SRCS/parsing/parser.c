/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:50:51 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 09:45:18 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static	bool	ft_check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
		return (true);
	else
		return (false);
}

char	**ft_parse(char *cmd_line, char **env)
{
	char	**cmds;
	char	**cmds2;
	char	*line;

	cmds = NULL;
	cmds2 = NULL;
	if (ft_check_empty_line(g_shell.cmd_line) == false)
	{
		add_history(cmd_line);
		if (cmd_line[0] == '|' || cmd_line[ft_strlen(cmd_line) - 1] == '|')
			return (ft_syntax_error());
		line = ft_expand(cmd_line, env);
		ft_tokenizer(line, env, 0);
		free(line);
		if (ft_lstsize(g_shell.token_list) == 0)
			return (NULL);
		if (ft_split_cmds_value(&cmds, &cmds2))
			return (NULL);
	}
	else
		free(g_shell.cmd_line);
	return (cmds2);
}

char	**ft_split_pipe(t_list *lst, int i)
{
	int		size;
	int		val;
	char	**ret;

	ret = ft_pipe_size(lst, &size);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = ft_strdup("");
		if (!ret)
			return (NULL);
		while (lst)
		{
			val = ft_split_util(&lst, &ret[i]);
			if (val == 1)
				return (NULL);
			else if (val == 2)
				break ;
		}
		++i;
	}
	ret[i] = NULL;
	return (ret);
}

char	*ft_build_cmd(char *str, t_list *lst)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(str);
	if (!tmp)
		return (NULL);
	free(str);
	tmp2 = ft_strjoin(tmp, " ");
	if (!tmp2)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	ret = ft_strjoin(tmp2, lst->content);
	if (!ret)
	{
		free(tmp2);
		return (NULL);
	}
	free(tmp2);
	return (ret);
}

char	**ft_lstoda(t_list *lst, char **cmds)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->pipe)
			cmds[i] = ft_strdup("|");
		else if (lst->content)
		{
			cmds[i] = ft_strdup(lst->content);
			if (!cmds[i])
			{
				ft_free_2d_char(&cmds);
				return (NULL);
			}
		}
		++i;
		lst = lst->next;
	}
	cmds[i] = NULL;
	return (cmds);
}
