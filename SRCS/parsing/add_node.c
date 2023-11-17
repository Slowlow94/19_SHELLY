/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:25:29 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/16 16:13:50 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_add_ope(char *cmd, int *i)
{
	char	*value;
	size_t	len;

	if (cmd[*i + 1] == '<' || cmd[*i + 1] == '<')
		len = 2;
	else
		len = 1;
	value = ft_substr(cmd, *i, len);
	ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
	*i += len;
}

void	ft_add_str(char *cmd, int *i)
{
	size_t	len;
	char	*value;

	*i += 1;
	len = ft_strchr_len(&cmd[*i], 39);
	if (ft_strchr(&cmd[*i], 39) != 0)
	{
		value = ft_substr(cmd, *i, len);
		ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
		*i += len + 1;
	}
	else
		*i += 1;
}

void	ft_add_str_var(char *cmd, int *i, char **env)
{
	size_t	len;
	char	*value;
	char	*var;

//printf("v = %s\n", value);
	*i += 1;
	len = ft_strchr_len(&cmd[*i], 34);
	if (ft_strchr(&cmd[*i], 34) != 0)
	{
		if (ft_strchr(&cmd[*i], '$'))
		{
			var = ft_expand_var(ft_strchr(&cmd[*i], '$'), env);
			value = ft_build_value(&cmd[*i], var);
		}
		else
			value = ft_substr(&cmd[*i], 0, len);
		ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
		*i += ft_strlen(value) + 1;
	}
	else
		*i += 1;
}

void	ft_add_var(char *cmd, int *i, char **env)
{
	size_t	key_len;
	char	*key;
	char	**var;

	key_len = ft_strchr_len(&cmd[*i + 1], 32);
	key = ft_substr(cmd, *i + 1, key_len);
	var = ft_get_var(key, key_len, env);
	while (*var)
	{
		ft_lstadd_back(&g_shell.token_list, ft_lstnew(*var));
		var++;
	}
	*i += key_len + 1;
}

void	ft_add_token(char *cmd, int *i)
{
	size_t	len;
	char	*value;

	len = ft_strchr_len(&cmd[*i], 32);
	value = ft_substr(&cmd[*i], 0, len);
	ft_lstadd_back(&g_shell.token_list, ft_lstnew(value));
	*i += ft_strlen(value);
}
