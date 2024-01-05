/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:44:27 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 09:53:19 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	**ft_syntax_error(void)
{
	free(g_shell.cmd_line);
	ft_printf("%s `|'\n", SYNTAX);
	g_shell.status = 258;
	return (NULL);
}
