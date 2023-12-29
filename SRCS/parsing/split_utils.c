/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:27:57 by gvardaki          #+#    #+#             */
/*   Updated: 2023/12/26 11:52:25 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_split_util(t_list **lst, char **ret)
{
	if ((*lst)->pipe)
	{
		*lst = (*lst)->next;
		return (2);
	}
	*ret = ft_build_cmd(*ret, *lst);
	if (!*ret)
		return (1);
	*lst = (*lst)->next;
	return (0);
}
