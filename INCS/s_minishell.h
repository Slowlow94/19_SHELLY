/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:19:54 by salowie           #+#    #+#             */
/*   Updated: 2023/11/17 11:28:17 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MINISHELL_H
# define S_MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <errno.h> 
# include <limits.h>

int	exec_builtins(char **argv);

// INITIALISATION STRUCTURE //
char	**create_my_envp(char **envp);

// BUILTINS //
int		ft_cd(char *path);
int		ft_echo(char **str, int i);
int		ft_envp(char **argv, int i);
int		ft_export(char **var, int i);
int		ft_unset(char **var, int i);
int		ft_pwd(void);
int		ft_exit(char *argv);

	// EXPORT UTILS //
int		export_without_cmd(int nbr_var);

		// ACTIONS IN ENV AND EXPORT // 
char	**add_var_to_export(char *var_to_add);
char	**add_to_var_in_env(char **envp, char *var);
char	**replace_var_in_env(char *var);
char	**add_new_to_env(char **envp, char *var, int nbr_var);
char	**del_var_export(char **e, char *var);
char 	**del_var_env(char **e, char *var);
char	**concat_double_tab(int nbr_var);
char	*cpy_second_tab_in_tab(char *e);

		// UTILS EXPORT & UNSET //
void	cpy_for_add_var(char *dst, char *src_add, char *src, int size);
void	ft_strlcpy_whithout_plus(char *dst, char *src, int size);
int		ft_strlen_from(char *str, int i);
int		is_var_exists(char **envp, char *var);
int		until(char *var, char c);
int		is_equal_str(char *stack, char *needle);
int		ft_strlen_double_tab(char **envp);
int		is_char(char *str, char c);
int		is_special_caracter(char *var);
int		is_already_in_export(char **check_to, char *var);
int		is_non_var_in_env(char **to_check, char *var);

	// FREE //
char	**free_envp_export_new(char **env, int i, char *str);
char	**free_envp_export(char *str);
void	ft_free_and_set_null(int nbr_var, char **str);
void	ft_free_and_set_null(int nbr_var, char **str);

#endif