/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:26:19 by gvardaki          #+#    #+#             */
/*   Updated: 2023/12/28 13:04:52 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <stdio.h>

void	ft_signal(void);
void	ft_int_handler(int num);
void	ft_quit_handler(int num);
void	ft_sigint_hd(int num);
void	ft_sigint_hdc(int num);
#endif
