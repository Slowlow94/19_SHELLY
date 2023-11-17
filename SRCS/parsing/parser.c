/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:50:51 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/16 16:13:50 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_print_stacks(t_list *a);

char	**ft_parse(char *cmd_line, char **env)
{
	char	**cmds;
	int		size;

	cmds = NULL;
	ft_tokenizer(cmd_line, env);
//	ft_print_stacks(g_minishell.token_list);
	size = ft_lstsize(g_shell.token_list);
//	printf("size = %d\n", size);
	cmds = malloc((size + 1) * sizeof (char *));
	cmds = ft_lstoda(g_shell.token_list, cmds);
	ft_lstclear(&g_shell.token_list, free);
	return (cmds);
}

char	**ft_lstoda(t_list *lst, char **cmds)
{
	int	i;

	i = 0;
	while (lst)
	{
		cmds[i] = ft_strdup(lst->content);
		++i;
		lst = lst->next;
	}
	cmds[i] = NULL;
	return (cmds);
}

void	ft_print_stacks(t_list*a)
{
	while (a)
	{
		// printf("%s\n", a->content);
		a = a->next;
	}
	ft_printf("\n");
}
