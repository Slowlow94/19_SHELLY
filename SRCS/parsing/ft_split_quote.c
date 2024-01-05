/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:29:43 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/03 10:00:46 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

size_t	ft_sublen(const char *s);

static int	ft_process_quote(char const *s, int *i)
{
	char	quote;

	quote = s[*i];
	*i += 1;
	while (s[*i] && s[*i] != quote)
		*i += 1;
	if (s[*i] == quote)
		*i += 1;
	return (0);
}

static int	ft_split_size(char const *s, char c)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
			{
				if (s[i] == '\'' || s[i] == '\"')
					ft_process_quote(s, &i);
				else
					i++;
			}
		}
		else
			i++;
	}
	return (j);
}

static char	**ft_fill_tab(char **tab, char const *s, char c)
{
	size_t		len;
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	len = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			len = ft_sublen(&s[j]);
			tab[i] = ft_substr(&s[j], 0, len);
			if (!tab[i])
			{
				ft_free_2d(tab);
				return (0);
			}
			j += len;
			i++;
		}
		else
			j++;
	}
	return (tab);
}

size_t	ft_sublen(const char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i] && s[i] != 32)
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			i++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] && s[i] == c)
				return (i + 1);
			else
				return (i);
		}
		i++;
	}
	return (i);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**split;
	int		size;

	if (!s)
		return (0);
	size = ft_split_size(s, c) + 1;
	split = malloc(sizeof(char *) * size);
	if (!split)
		return (0);
	split = ft_fill_tab(split, s, c);
	if (!split)
		return (0);
	split[size - 1] = 0;
	return (split);
}
