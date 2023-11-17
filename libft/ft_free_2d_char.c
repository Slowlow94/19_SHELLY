/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:01:39 by gvardaki          #+#    #+#             */
/*   Updated: 2023/11/16 14:08:00 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_free_2d_char(char **str, int nbr_cmd)
{
    int i;
	
    i = 0;
    if (!str)
        return ;
    while (i < (nbr_cmd - 1) && str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
