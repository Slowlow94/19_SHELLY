/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:29 by salowie           #+#    #+#             */
/*   Updated: 2023/11/14 11:08:49 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/minishell.h"

int	ft_pwd(void)
{
	char	path[PATH_MAX];

	printf ("%s\n", getcwd(path, sizeof(path)));
	return (0);
}
