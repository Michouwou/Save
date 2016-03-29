/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_widths.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:40:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int     *ft_get_widths(t_tree *tree, int *tab)
{
    if (tree->left)
        tab = ft_get_widths(tree->left, tab);
    if (tree->right)
        tab = ft_get_widths(tree->right, tab);
    tab[0] = ft_max(ft_strlen(tree->data->name), tab[0]);
    tab[1] = WIN_WIDTH / tab[0];
    tab[2] = ft_max(ft_strlen(tree->data->date_num), tab[2]);
    tab[3] = ft_max(ft_strlen(ft_itoa(tree->data->size)), tab[3]);
    tab[4] = ft_max(ft_strlen(tree->data->group_name), tab[4]);
    tab[5] = ft_max(ft_strlen(tree->data->user_name), tab[5]);
    tab[6] = ft_max(ft_strlen(ft_itoa(tree->data->links)), tab[6]);
    return (tab);
}