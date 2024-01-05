/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:20:41 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/04 09:45:13 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define SYNTAX "minishell: syntax error near unexpected token"

// parser
char	**ft_parse(char *cmd, char **env);
char	**ft_lstoda(t_list *lst, char **cmds);
char	**ft_split_pipe(t_list *lst, int i);
char	*ft_build_cmd(char *str, t_list *lst);
char	*ft_expand(char *line, char **env);

// tokenizer
void	ft_tokenizer(char *cmd, char **env, int i);
void	ft_error_list(t_list **lst, int err);

// add_node
int		ft_add_ope(char *cmd, int *i);
int		ft_add_str(char *cmd, int *i);
int		ft_add_str_var(char *cmd, int *i, char **env);
int		ft_add_token(char *cmd, int *i, int j);

// utils
size_t	ft_strchr_len(char *s, int c);
size_t	ft_str2chr_len(char *s, int c, int d);
char	*ft_expand_var(char *str, char **env);
char	*ft_build_value(char *cmd, char **env, int len);
void	ft_free_matrix(char **map);
char	*ft_get_key(char *str, size_t *key_len);
char	ft_isvar_env(char *str);
char	**ft_pipe_size(t_list *lst, int *size);
int		ft_split_util(t_list **lst, char **ret);
int		ft_split_cmds_value(char ***cmds, char ***cmds2);
size_t	ft_shortest(char *s, char a, char b, char c);
char	**ft_syntax_error(void);

//analyzer
int		ft_analyze(char **cmd);
int		ft_check_file(char *path);
int		ft_check_outfile(char *path);

//heredoc
int		ft_add_heredoc(char *cmd, int *i);
void	create_tmp_file(char *limiter, char *file);
char	**ft_check_delim(char *str, int	*err, int *i);
int		ft_here_doc_fork(char *limiter, char *file);
#endif
