//ajout header
#include "../INCS/minishell.h"

t_shell	g_shell;

void	ft_print_cmds(char **cmd);

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	if (env[0] == NULL)
	{
		printf("Sorry, our minishell need environnement, please try again \n");
		return (1);
	}
	if (ft_initshell(env) == 1)
		return (1);
	while (1)
	{
		ft_signal();
		g_shell.cmd_line = readline(" minishell $> ");
		if (!g_shell.cmd_line)
		{
			ft_free_2d_char(&g_shell.my_env);
			ft_free_all(&g_shell);
			ft_exit(0);
			exit(g_shell.status);
		}	
		g_shell.cmds_redir = ft_parse(g_shell.cmd_line, g_shell.my_env);
		// ft_print_cmds(g_shell.cmds_redir);
		if (g_shell.cmds_redir)
			ft_process();
		ft_clean();
	}
	ft_free_all(&g_shell);
	return (0);
}

// delete fct
void	ft_print_cmds(char **cmd)
{
	int	i;

	i = 0;
	ft_printf("after parse\n");
	while (cmd[i])
	{
		printf("cmd [%d] = %s\n", i, cmd[i]);
		++i;
	}
}
