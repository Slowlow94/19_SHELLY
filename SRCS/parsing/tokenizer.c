/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:48:42 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/10 12:41:14 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static	bool	ft_is_skip(char c)
{
	if (c == 32 || c == 92 || c == ';')
		return (true);
	else
		return (false);
}

void	ft_tokenizer(char *cmd, char **env)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_is_skip(cmd[i]))
			i++;
		else if (cmd[i] == '<' || cmd [i] == '>')
			ft_add_ope(cmd, &i);
		else if (cmd[i] == 39)
			ft_add_str(cmd, &i);
		else if (cmd[i] == 34)
			ft_add_str_var(cmd, &i, env);
		else if (cmd[i] == '$')
			ft_add_var(cmd, &i, env);
		else
		{
			ft_add_token(cmd, &i);
//printf("ici\n");
		}
//		sleep(1);
//printf("i = %d\n", i);
	}
}
