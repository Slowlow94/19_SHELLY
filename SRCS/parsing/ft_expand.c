/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:23:22 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 13:15:33 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static char	*ft_replace(char *s, size_t start, size_t n, char *sub)
{
	size_t	i;
	size_t	sublen;
	size_t	len;
	char	*tmp;

	sublen = ft_strlen(sub);
	len = ft_strlen(s) - n + sublen;
	tmp = malloc(len + 1);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < start)
		tmp[i] = s[i];
	i--;
	while (++i < start + sublen)
		tmp[i] = sub[i - start];
	i--;
	while (++i < len)
		tmp[i] = s[i - sublen + n];
	tmp[i] = 0;
	return (tmp);
}

static int	ft_expand_status(char **s, size_t i)
{
	char	*n;
	char	*tmp;

	n = ft_itoa(g_shell.status);
	if (!n)
		return (0);
	tmp = ft_replace(*s, i, 2, n);
	free(*s);
	free(n);
	*s = tmp;
	if (!*s)
		return (0);
	return (1);
}

static int	ft_expand_var_env(char **s, size_t i, char **env)
{
	char	*var;
	char	*tmp;

	var = ft_expand_var(&(*s)[i], env);
	if (!var)
	{
		tmp = ft_replace(*s, i, ft_var_len(&(*s)[i + 1]) + 1, "");
		free(*s);
		*s = tmp;
		if (!*s)
			return (0);
		return (1);
	}
	tmp = ft_replace(*s, i, ft_var_len(&(*s)[i + 1]) + 1, var);
	free(var);
	free(*s);
	*s = tmp;
	if (!*s)
		return (0);
	return (1);
}

char	*ft_expand(char *str, char **env)
{
	t_expand_var	arg;

	if (!str || !env)
		return (0);
	arg = ft_init_arg(str);
	if (!arg.line)
		return (NULL);
	while (++arg.i < ft_strlen(arg.line))
	{
		if (arg.line[arg.i] == 39 && !ft_is_in_dquotes(arg.line, arg.i))
			arg.is_in_quote = !arg.is_in_quote;
		if (arg.is_in_quote)
			continue ;
		if (arg.line[arg.i] == '$' && arg.line[arg.i + 1] == '?')
		{
			if (!ft_expand_status(&arg.line, arg.i))
				return (0);
		}
		else if (arg.line[arg.i] == '$' && (arg.line[arg.i + 1] == '_'
				|| ft_isalpha(arg.line[arg.i + 1])))
			if (!ft_expand_var_env(&arg.line, arg.i, env))
				return (0);
	}
	return (arg.line);
}
