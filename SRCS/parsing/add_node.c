/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:25:29 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 09:54:47 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_add_ope(char *cmd, int *i)
{
	char	*value;
	size_t	len;

	if (cmd[*i + 1] == '<')
		return (ft_add_heredoc(cmd, i));
	else
	{
		if (cmd[*i + 1] == '>')
			len = 2;
		else
			len = 1;
		value = ft_substr(cmd, *i, len);
		if (!value)
			return (1);
		ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
		*i += len;
	}
	return (0);
}

int	ft_add_str(char *cmd, int *i)
{
	size_t	len;
	char	*value;

	*i += 1;
	len = ft_strchr_len(&cmd[*i], 39);
	if (ft_strchr(&cmd[*i], 39) != 0)
	{
		value = ft_substr(cmd, *i, len);
		if (!value)
			return (1);
		ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
		*i += len + 1;
	}
	else
		*i += 1;
	return (0);
}

int	ft_add_str_var(char *cmd, int *i, char **env)
{
	size_t	len;
	char	*value;

	if (ft_strchr(&cmd[*i + 1], 34) != 0)
	{
		len = ft_strchr_len(&cmd[*i + 1], 34) + 2;
		if (ft_strchr(&cmd[*i], '$'))
			value = ft_build_value(&cmd[*i], env, len);
		else
			value = ft_substr(&cmd[*i], 0, len);
		if (!value)
			return (1);
		*i += len;
		ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
	}
	else
		*i += 1;
	return (0);
}

int	ft_add_token(char *cmd, int *i, int j)
{
	size_t	len;
	size_t	pipe_len;
	char	*value;
	char	c;

	c = ft_isvar_env(&cmd[*i]);
	if (c)
	{
		j = ft_strchr_len(&cmd[*i], c);
		len = j + ft_strchr_len(&cmd[*i + j + 1], c) + 2;
	}
	else
	{
		len = ft_shortest(&cmd[*i], 32, 34, 39);
		pipe_len = ft_strchr_len(&cmd[*i], '|');
		if (pipe_len < len)
			len = pipe_len;
	}
	value = ft_substr(&cmd[*i], 0, len);
	if (!value)
		return (1);
	ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
	*i += ft_strlen(value);
	return (0);
}
