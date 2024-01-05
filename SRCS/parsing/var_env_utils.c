/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:49:07 by gvardaki          #+#    #+#             */
/*   Updated: 2024/01/03 13:10:49 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

char	*ft_expand_var(char *str, char **env)
{
	char	*key;
	char	*var;
	size_t	key_len;
	int		i;

	var = NULL;
	key = ft_get_key(str, &key_len);
	if (!key)
		return (0);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, key_len) != 0)
			i++;
		else
		{
			var = ft_substr(env[i], key_len + 1, ft_strlen(env[i]));
			if (!var)
				var = NULL;
			break ;
		}
	}
	free(key);
	return (var);
}

char	*ft_get_key(char *str, size_t *key_len)
{
	char	*key;
	int		i;

	i = 1;
	while (ft_isalnum(str[i]) || (str[i] == '_'))
		i++;
	if (i == 1)
		return (NULL);
	*key_len = i - 1;
	key = ft_substr(str, 1, *key_len);
	if (!key)
		return (0);
	return (key);
}

char	ft_isvar_env(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 32)
	{
		if (str[i] == '=')
		{
			while (str[i] && str[i] != 32)
			{
				if (str[i] == 39 || str[i] == 34)
					return (str[i]);
				++i;
				if (!str[i])
					return (0);
			}
		}
		++i;
	}
	return (0);
}
