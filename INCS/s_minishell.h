#ifndef S_MINISHELL_H
# define S_MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <errno.h> 
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

// BUILTINS //
int	ft_cd(char *path);
int	ft_echo(char **str, int i);
int	ft_envp(char **envp);
int	ft_export(char **envp, char *cmd);
int ft_pwd(void);

#endif