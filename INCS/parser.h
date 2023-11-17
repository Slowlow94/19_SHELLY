/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:20:41 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/08 10:27:29 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// parser
char	**ft_parse(char *cmd, char **env);
char	**ft_lstoda(t_list *lst, char **cmds);

// tokenizer
void	ft_tokenizer(char *cmd, char **env);

// add_node
void	ft_add_ope(char *cmd, int *i);
void	ft_add_str(char *cmd, int *i);
void	ft_add_str_var(char *cmd, int *i, char **env);
void	ft_add_var(char *cmd, int *i, char **env);
void	ft_add_token(char *cmd, int *i);

// utils
size_t	ft_strchr_len(char *s, int c);
char	*ft_expand_var(char *str, char **env);
char	*ft_build_value(char *cmd, char *var);
void	ft_add_str_var(char *cmd, int *i, char **env);
char	**ft_get_var(char *key, int key_len, char **env);

#endif
