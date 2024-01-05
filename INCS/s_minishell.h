/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:14:36 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 13:17:47 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MINISHELL_H
# define S_MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>

typedef struct s_pipe
{
	char	**decomp_path;
	char	**decomp_cmd;
	int		in;
	int		out;
	int		pipe_nbr;
	int		**fd;
	int		status;
}	t_pipe;

typedef struct s_lst
{
	char			**cmd;
	char			*infile;
	char			*outfile;
	char			*out_replace;
	struct s_lst	*next;
}					t_lst;

// ROLES ATTRIBUTION //
void	ft_div_tab(void);
char	**ft_split_quote(char const *s, char c);

// LINKED LIST //
int		ft_add_to_linked_list(char *in, char *out, char *out_rep, char **cmds);
int		ft_lc_size(t_lst *lst);
t_lst	*ft_lc_new(char *in, char *out, char *out_rep, char **cmds);
t_lst	*create_node(char *in, char *out, char *out_rep);
t_lst	*create_infile_node(t_lst **node, char *in);
t_lst	*ft_lc_last(t_lst *lst);
void	ft_lc_add_back(t_lst **lst, t_lst *new);
void	ft_lc_clear(t_lst **lst);

// PIPE //
void	ft_process(void);
void	init_pipe(t_pipe *pipex);
void	is_creating_pipe_ok(void);
int		create_pipe(t_pipe *pipex, int nbr_pipe);
void	wich_process(t_lst *list);
void	no_pipe(t_lst *list);
void	in_out_no_pipe(t_lst *list, t_pipe *pipex);
void	ft_get_file_descriptors(t_pipe *pipex, t_lst *list);
void	ft_get_file_descriptors_out(t_pipe *pipex, t_lst *list);
void	child_process(t_pipe pipex, int i, t_lst *list);
void	close_all_pipe(t_pipe *pipex);
void	parsing_path(t_pipe *pipex, char **cmd);
void	check_cmd(t_pipe pipex);
void	parent_process(t_pipe pipex, pid_t pid);
void	check_status(t_pipe pipex, int *statuses);
void	no_pipe_builtins(t_lst *list);
void	ft_relative_path(t_pipe *pipex, char **cmd, char *start);
void	ft_absolut_path(t_pipe *pipex, char **cmd, int i);
char	*looking_for_start(char **str, const char *s2, int size);
char	*ft_strjoin_3(char const *s1, char c, char const *s2);
int		ft_where_is_char(char *cmd);

// FREE EXEC //
void	free_rev_double_tab(t_pipe *pipex, int i);

// INITIALISATION //
char	**create_my_envp(char **envp);
char	**ft_argv_cmd(char **cmds, int j);

// BUILTINS //
int		exec_builtins(char **argv);
int		is_builtins(char **argv);
int		ft_cd(char *path);
int		ft_echo(char **str, int i);
int		ft_envp(char **argv, int i);
int		ft_export(char **var, int i);
int		ft_unset(char **var, int i, int res);
int		ft_pwd(void);
void	add_pwd(void);
int		ft_exit(char **argv, int i, int j);

	// EXPORT UTILS //
int		export_without_cmd(int nbr_var);

		// ACTIONS IN ENV AND EXPORT //
char	**add_var_to_export(char *var_to_add);
char	**add_to_var_in_env(char **envp, char *var);
char	**replace_var_in_env(char *var);
char	**add_new_to_env(char **envp, char *var, int nbr_var);
char	**del_var_export(char **e, char *var);
char	**del_var_env(char **e, char *var);
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

	// FREE BUILTINS //
char	**free_envp_export_new(char **env, char *str);
char	**free_envp_export(char *str);
void	ft_free_and_set_null(char **str);

#endif
