/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:02:53 by salowie           #+#    #+#             */
/*   Updated: 2024/01/02 13:50:23 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_add_to_linked_list(char *in, char *out, char *out_rep, char **cmds)
{
	t_lst	*new_node;

	if (g_shell.elem_to_pipe == NULL)
		g_shell.elem_to_pipe = ft_lc_new(in, out, out_rep, cmds);
	else
	{
		new_node = ft_lc_new(in, out, out_rep, cmds);
		if (new_node == NULL)
		{
			ft_lc_clear(&g_shell.elem_to_pipe);
			return (1);
		}
		ft_lc_add_back(&g_shell.elem_to_pipe, new_node);
	}
	return (0);
}

t_lst	*ft_lc_new(char *in, char *out, char *out_rep, char **cmds)
{
	t_lst	*node;

	node = create_node(in, out, out_rep);
	if (!node)
		return (NULL);
	node->cmd = cmds;
	node->next = NULL;
	return (node);
}

t_lst	*create_node(char *in, char *out, char *out_rep)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node = create_infile_node(&node, in);
	if (!out)
		node->outfile = NULL;
	else
	{
		node->outfile = ft_strdup(out);
		if (!node->outfile)
			return (NULL);
	}
	if (!out_rep)
		node->out_replace = NULL;
	else
	{
		node->out_replace = ft_strdup(out_rep);
		if (!node->out_replace)
			return (NULL);
	}
	return (node);
}

t_lst	*create_infile_node(t_lst **node, char *in)
{
	if (!in)
		(*node)->infile = NULL;
	else
	{
		(*node)->infile = ft_strdup(in);
		if (!(*node)->infile)
			return (NULL);
	}
	return (*node);
}

t_lst	*ft_lc_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
