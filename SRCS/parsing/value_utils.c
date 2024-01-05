/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:20:50 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/03 17:17:00 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static char	*ft_build_val_loop(char *cmd, char **env, int len, char *value)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = ft_str2chr_len(&cmd[i], '$', 34);
		if (j != 0)
		{
			value = ft_strjoin(value, ft_substr(&cmd[i], 0, j));
			while (cmd[i] != '$' && cmd[i] != 34)
				i++;
		}
		else
		{
			str = ft_expand_var(&cmd[i++], env);
			value = ft_strjoin(value, str);
			while (ft_isalnum(cmd[i]) || (cmd[i] == '_'))
				++i;
		}
		if (!value)
			return (0);
	}
	return (value);
}

char	*ft_build_value(char *cmd, char **env, int len)
{
	char	*value;

	value = ft_calloc(1, sizeof (char));
	if (!value)
		return (0);
	value = ft_build_val_loop(cmd, env, len, value);
	return (value);
}

int	ft_split_cmds_value(char ***cmds, char ***cmds2)
{
	int	ret;

	*cmds = malloc((ft_lstsize(g_shell.token_list) + 1) * sizeof (char *));
	if (!*cmds)
		ft_error_list(&g_shell.token_list, 1);
	*cmds = ft_lstoda(g_shell.token_list, *cmds);
	*cmds2 = ft_split_pipe(g_shell.token_list, 0);
	if (!cmds2)
		ft_error_list(&g_shell.token_list, 1);
	ft_lstclear(&g_shell.token_list, free);
	ret = ft_analyze(*cmds);
	if (ret != 0)
	{
		g_shell.status = ret;
		ft_free_matrix(*cmds);
		ft_free_matrix(*cmds2);
		return (1);
	}
	ft_free_matrix(*cmds);
	return (0);
}
