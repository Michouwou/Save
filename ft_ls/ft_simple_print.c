/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:40:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * Le tableau widths contiendra la largeur des noms a l'index 0 et le nombre
 * d'elements par ligne a l'inde 1
**/

void    ft_simple_print(t_tree *tree, int *widths)
{
    if (widths[1] == 0)
    {
        ft_printf("\n");
        widths[1] = WIN_WIDTH / widths[0];
    }
    ft_printf("%*s", widths[0], tree->data->name);
    widths[1]--;
}