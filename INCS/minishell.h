/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:22:26 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/16 16:13:50 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "parser.h"
# include "s_minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_shell
{
	char	*cmd_line;
	char	**env_list;
	int		cmd_nbr;
	char	**my_envp;
	char	**export;
	t_list	*token_list;
}	t_shell;

extern t_shell	g_shell;

#endif
