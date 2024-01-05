/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:53:21 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 15:49:24 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static int	ft_cmd_size(char **cmds)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i][0] == '<' || cmds[i][0] == '>')
		{
			i += 2;
			continue ;
		}
		++size;
		++i;
	}
	return (size);
}

char	**ft_argv_cmd(char **cmds, int j)
{
	int		size;
	int		k;
	char	**ret;

	size = ft_cmd_size(cmds);
	ret = malloc(sizeof (char *) * (size + 1));
	if (!ret)
		return (NULL);
	k = 0;
	while (k < size)
	{
		if (cmds[k][0] == '<' || cmds[k][0] == '>')
			k += 2;
		ret[j] = ft_strdup(cmds[k]);
		if (!ret[j])
		{
			ft_free_2d_char(&ret);
			return (NULL);
		}
		k++;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
