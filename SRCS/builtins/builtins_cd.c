/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:02:33 by salowie           #+#    #+#             */
/*   Updated: 2024/01/04 15:57:09 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

static void	add_oldpwd(void)
{
	char	*path;
	char	*old;
	char	dir[PATH_MAX];
	int		nbr_variables;

	nbr_variables = ft_strlen_double_tab(g_shell.my_env);
	path = getcwd(dir, sizeof(dir));
	if (path == NULL)
		return ;
	old = ft_strjoin("OLDPWD=", path);
	if (!old)
		ft_error_free_and_close(&g_shell, old);
	if (is_var_exists(g_shell.my_env, "OLDPWD=") == 1)
		g_shell.my_env = replace_var_in_env(old);
	else
		g_shell.my_env = add_new_to_env(g_shell.my_env, old, nbr_variables);
	free(old);
}

static int	ft_cd_dash(void)
{
	char	*start;
	char	*path_envp;

	start = looking_for_start(g_shell.my_env, "OLDPWD", 5);
	if (!start)
	{
		printf("minishell $>: cd: OLDPWD not set\n");
		return (1);
	}
	path_envp = ft_substr(start, 7, ft_strlen(start) - 1);
	if (!path_envp)
		ft_error_free_and_close(&g_shell, "path_envp");
	printf("%s\n", path_envp);
	free(path_envp);
	return (0);
}

static int	ft_cd_nopath(void)
{
	char	dir[PATH_MAX];
	char	*path_envp;
	char	*start;

	start = looking_for_start(g_shell.my_env, "HOME=", 4);
	if (!start)
	{
		printf("minishell $>: cd: HOME not set\n");
		return (1);
	}
	path_envp = ft_substr(start, 5, ft_strlen(start) - 1);
	if (!path_envp)
		ft_error_free_and_close(&g_shell, "path_envp");
	if (chdir(path_envp) == 0 && getcwd(dir, sizeof(dir)) != NULL)
	{
		free(path_envp);
		return (0);
	}
	free(path_envp);
	return (0);
}

int	ft_cd_2(char *path)
{
	add_oldpwd();
	if (ft_strncmp(path, "..", 3) == 0)
		printf("cd: error retrieving current directory\n");
	else
		printf("cd: %s: No such file or directory\n", path);
	return (1);
}

int	ft_cd(char *path)
{
	char	dir[PATH_MAX];

	if (getcwd(dir, sizeof(dir)) != NULL 
		&& path && ((!ft_strncmp(path, "-", 2)) == 0))
		add_oldpwd();
	if (!path)
	{
		if (ft_cd_nopath() == 1)
			return (1);
		return (0);
	}
	else if (ft_strncmp(path, ".", 2) == 0)
		return (0);
	else if (ft_strncmp(path, "-", 2) == 0)
		return (ft_cd_dash());
	else if (chdir(path) == 0 && getcwd(dir, sizeof(dir)) != NULL)
	{
		add_pwd();
		return (0);
	}
	if (ft_cd_2(path) == 1)
		return (1);
	return (0);
}
