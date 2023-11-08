/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:25:40 by salowie           #+#    #+#             */
/*   Updated: 2023/11/07 17:59:00 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/s_minishell.h"

void	free_double_tab_char(char **str, int nbr_cmd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (i < nbr_cmd - 1 && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
