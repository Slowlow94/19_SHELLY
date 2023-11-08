/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:19:54 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 18:24:24 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MINISHELL_H
# define S_MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <errno.h> 
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shelly {
	char	**my_envp;
	char	**my_args;
}				t_shelly;

extern t_shelly	g_shell;

// INITIALISATION STRUCTURE //
char	**create_my_envp(char **envp);

// BUILTINS //
	// CD //
int		ft_cd(char *path);

	// ECHO //
int		ft_echo(char **str, int i);

	// ENV //
int		ft_envp(char **envp, char **argv, int i);

	// EXPORT //
int		ft_export(char **envp, char *cmd);
int		export_without_cmd(char **envp, int nbr_variables);
int		is_var_exists(char **envp, char *var);
int		ft_strlen_from(char *str, int i);
int		until_plus(char *var, char c);
void	ft_strlcpy_whithout_plus(char *dst, char *src, int size);
void	cpy_for_add_var(char *dst, char *src_add, char *src, int size);

	// PWD //
int		ft_pwd(void);

	// EXIT //
int		ft_exit(char *argv);

// UTILS //
int		is_equal_str(char *stack, char *needle);
int		is_equal(char *str, char c);
int		nbr_variables_envp(char **envp);

// FREE //
void	free_double_tab_char(char **str, int nbr_cmd);

#endif