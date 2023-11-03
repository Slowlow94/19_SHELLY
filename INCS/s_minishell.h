/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:19:54 by salowie           #+#    #+#             */
/*   Updated: 2023/11/03 17:53:37 by salowie          ###   ########.fr       */
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

// BUILTINS //
int	ft_cd(char *path);
int	ft_echo(char **str, int i);
int	ft_envp(char **envp, char **argv, int i);
int	ft_export(char **envp, char *cmd);
int	ft_pwd(void);
int	ft_exit(char *argv);

// FREE //
void	free_double_tab_char(char **str, int nbr_cmd);

#endif