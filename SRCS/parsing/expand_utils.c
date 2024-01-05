/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:09:37 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/03 08:53:02 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

t_expand_var	ft_init_arg(char *str)
{
	t_expand_var	arg;

	arg.line = ft_strdup(str);
	free(str);
	arg.i = -1;
	arg.is_in_quote = false;
	return (arg);
}

size_t	ft_var_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
		i++;
	return (i);
}

bool	ft_is_in_dquotes(const char *str, size_t i)
{
	bool	dq;
	bool	sq;
	size_t	j;

	dq = false;
	sq = false;
	j = 0;
	while (j < i) 
	{
		if (str[j] == '"' && !sq)
		{
			dq = !dq;
		}
		if (str[j] == '\'' && !dq)
		{
			sq = !sq;
		}
		++j;
	}
	return (dq);
}

bool	ft_var_with_space(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	while (s[i])
	{
		if (s[i] == 32)
			return (true);
		i++;
	}
	return (false);
}
