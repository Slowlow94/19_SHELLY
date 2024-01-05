/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:29 by salowie           #+#    #+#             */
/*   Updated: 2024/01/02 13:48:01 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

void	add_pwd(void)
{
	char	*path;
	char	*pwd;
	char	dir[PATH_MAX];
	int		nbr_variables;

	nbr_variables = ft_strlen_double_tab(g_shell.my_env);
	path = getcwd(dir, sizeof(dir));
	pwd = ft_strjoin("PWD=", path);
	if (!pwd)
		ft_error_free_and_close(&g_shell, pwd);
	if (is_var_exists(g_shell.my_env, "PWD=") == 1)
		g_shell.my_env = replace_var_in_env(pwd);
	else
		g_shell.my_env = add_new_to_env(g_shell.my_env, pwd, nbr_variables);
	free(pwd);
}

static void	add_deleted_pwd(char *pwd)
{
	int		nbr_variables;

	nbr_variables = ft_strlen_double_tab(g_shell.my_env);
	if (is_var_exists(g_shell.my_env, "PWD=") == 1)
		g_shell.my_env = replace_var_in_env(pwd);
	else
		g_shell.my_env = add_new_to_env(g_shell.my_env, pwd, nbr_variables);
	printf("%s\n", pwd);
	free(pwd);
}

static void	add_deleted_oldpwd(char *pwd)
{
	int		nbr_variables;

	nbr_variables = ft_strlen_double_tab(g_shell.my_env);
	if (is_var_exists(g_shell.my_env, "OLDPWD=") == 1)
		g_shell.my_env = replace_var_in_env(pwd);
	else
		g_shell.my_env = add_new_to_env(g_shell.my_env, pwd, nbr_variables);
}

static int	ft_pwd_2(void)
{
	char	*pwd_mod;
	char	*good_pwd;
	char	*final_pwd;

	pwd_mod = looking_for_start(g_shell.my_env, "PWD=", 3);
	if (!pwd_mod)
	{
		printf("minishell $>: cd: PWD not set\n");
		return (1);
	}
	add_deleted_oldpwd(ft_strjoin("OLD", pwd_mod));
	good_pwd = ft_substr(pwd_mod, 4, ft_strlen(pwd_mod) - 1);
	if (!good_pwd)
	{
		free(good_pwd);
		ft_error_free_and_close(&g_shell, good_pwd);
	}
	final_pwd = ft_strjoin(good_pwd, "/..");
	if (!final_pwd)
	{
		free(final_pwd);
		ft_error_free_and_close(&g_shell, final_pwd);
	}
	add_deleted_pwd(final_pwd);
	return (0);
}

int	ft_pwd(void)
{
	char	path[PATH_MAX];

	if (getcwd(path, sizeof(path)) != NULL)
	{
		printf ("%s\n", getcwd(path, sizeof(path)));
		add_pwd();
	}
	else
	{
		if (ft_pwd_2() == 1)
			return (1);
	}
	return (0);
}
