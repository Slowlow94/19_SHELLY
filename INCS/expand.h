/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:14:30 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/02 16:25:09 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

typedef struct s_expand_var
{
	size_t		i;
	char		*line;
	bool		is_in_quote;

}				t_expand_var;

t_expand_var	ft_init_arg(char *str);
bool			ft_is_in_dquotes(const char *str, size_t i);
size_t			ft_var_len(const char *s);
bool			ft_var_with_space(char *s);
#endif
