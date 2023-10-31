/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:04:29 by salowie           #+#    #+#             */
/*   Updated: 2023/10/30 12:04:35 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

int ft_pwd()
{
	char path[PATH_MAX];

	printf ("%s\n", getcwd(path, sizeof(path)));
	return (0);
}
