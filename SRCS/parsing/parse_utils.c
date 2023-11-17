/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:35:01 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/13 11:11:27 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

size_t	ft_strchr_len(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i])
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (i);
}

char	*ft_expand_var(char *str, char **env)
{
	char	*key;
	char	*var;
	int		key_len;
	int		i;

	i = ft_strchr_len(str, 34) - 1;
	key_len = ft_strchr_len(str, 32) - 1;
	var = NULL;
	if (key_len > i)
		key_len = i;
	key = ft_substr(str, 1, key_len);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, key_len) != 0)
			i++;
		else
		{
			var = ft_substr(env[i], key_len + 1, ft_strlen(env[i]));
			break ;
		}
	}
	return (var);
}

char	*ft_build_value(char *cmd, char *var)
{
	char	*value;
	char	*str;
	char	*half_str;
	int		post_var_pos;

	half_str = ft_substr(cmd, 1, ft_strchr_len(cmd, '$'));
	str = ft_strjoin(half_str, var);
	free(half_str);
	post_var_pos = ft_strchr_len(ft_strchr(cmd, '$'), 32);
	half_str = ft_substr(cmd, post_var_pos, ft_strchr_len(cmd, 39));
	value = ft_strjoin(str, half_str);
	free(half_str);
	return (value);
}

char	**ft_get_var(char *key, int key_len, char **env)
{
	char	**var;
	char	**tmp;

	var = NULL;
	tmp = NULL;
	while (*env || (ft_strncmp(key, *env, key_len) != 0))
		env++;
	if (ft_strncmp(key, *env, key_len) == 0)
		tmp = ft_split(*env, '=');
	if (*tmp)
		var = ft_split(tmp[1], 32);
	return (var);
}
