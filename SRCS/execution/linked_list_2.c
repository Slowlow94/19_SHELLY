/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:34:15 by salowie           #+#    #+#             */
/*   Updated: 2024/01/03 10:44:40 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_lc_add_back(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lc_last(*lst)->next = new;
}

void	ft_lc_clear(t_lst **lst)
{
	t_lst	*temp;

	temp = NULL;
	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		if (temp->infile != NULL)
			ft_free((void **)&temp->infile);
		if (temp->outfile != NULL)
			ft_free((void **)&temp->outfile);
		if (temp->out_replace != NULL)
			ft_free((void **)&temp->out_replace);
		if (temp->cmd != NULL)
			ft_free_2d_char(&temp->cmd);
		*lst = (*lst)->next;
		ft_free((void **)&temp);
	}
	*lst = NULL;
}
