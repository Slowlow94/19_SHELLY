/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:47:06 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 16:04:38 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "parser.h"
# include "s_minishell.h"
# include "signals.h"
# include "expand.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <signal.h>
# include <histedit.h>
# include <termios.h>
# include <stdbool.h>

# define ENV "Sorry, our minishell need environnement, please try again"

typedef struct s_shell
{
	char			*cmd_line;
	char			**cmds_redir;
	char			**my_env;
	char			**export;
	t_list			*token_list;
	t_lst			*elem_to_pipe;
	t_pipe			pipex;
	struct termios	term;
	bool			child;
	int				status;
	int				signal;
	bool			env;
	bool			here_doc;
}			t_shell;

extern t_shell	g_shell;

int		ft_initshell(char **env);
int		ft_clean(void);
void	ft_main_exit(void);

// FREE // 
void	ft_free(void **value);
void	ft_free_2d_int(int ***fd);
void	ft_free_2d_char(char ***str);
void	ft_free_struct(t_pipe *pipex);
void	ft_free_all(t_shell *shell);
void	ft_error_free_and_close(t_shell *shell, char *str);

#endif
