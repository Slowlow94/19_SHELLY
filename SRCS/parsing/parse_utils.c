/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:35:01 by gvardaki          #+#    #+#             */
/*   Updated: 2023/12/26 10:14:05 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

size_t	ft_str2chr_len(char *s, int c, int d)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i] != (char)d && s[i])
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (i);
}

size_t	ft_strchr_len(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i])
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (i);
}

void	ft_free_matrix(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (i > 0)
		free(map);
	map = NULL;
}

char	**ft_pipe_size(t_list *lst, int *size)
{
	char	**ret;

	*size = 1;
	while (lst)
	{
		if (lst->pipe)
			*size += 1;
		lst = lst->next;
	}
	ret = malloc(sizeof (char *) * (*size + 1));
	if (!ret)
		return (NULL);
	return (ret);
}
