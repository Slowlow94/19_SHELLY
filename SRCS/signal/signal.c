/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:52:11 by gvardaki          #+#    #+#             */
/*   Updated: 2023/12/28 13:22:07 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	ft_int_handler(int num)
{
	(void)num;
	if (g_shell.child == true)
	{
		ft_putstr_fd("^C\n", 1);
		g_shell.child = false;
	}
	else
	{
		printf("\n");
		rl_on_new_line();
	}
		rl_replace_line("", 0);
		rl_redisplay();
}

void	ft_quit_handler(int num)
{
	(void)num;
	ft_printf("Quit: 3\n");
}

void	ft_signal(void)
{
	struct termios	term;

	term = g_shell.term;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, ft_int_handler);
	signal(SIGQUIT, SIG_IGN);
	g_shell.child = false;
}

void	ft_sigint_hd(int num)
{
	(void)num;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_shell.status = 1;
}

void	ft_sigint_hdc(int num)
{
	(void)num;
	write(1, "\n", 1);
	rl_on_new_line();
	exit(0);
}
