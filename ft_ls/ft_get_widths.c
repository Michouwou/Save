/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_widths.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 14:56:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

static int  *int_tab(void)
{
	int *tab;
	int i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int     *ft_get_widths(t_tree *tree, int *tab)
{
	if (tree->left && tree->left->data)
		tab = ft_get_widths(tree->left, tab);
	if (tree->right && tree->right->data)
		tab = ft_get_widths(tree->right, tab);
	if (!tab)
		tab = int_tab();
	tab[0] = ft_max(ft_strlen(tree->data->name), tab[0]);
	tab[1] = WIN_WIDTH / (tab[0] + 1);
	tab[2] = ft_max(ft_strlen(tree->data->date_num), tab[2]);
	tab[3] = ft_max(ft_strlen(ft_itoa(tree->data->size)), tab[3]);
	tab[4] = ft_max(ft_strlen(tree->data->group_name), tab[4]);
	tab[5] = ft_max(ft_strlen(tree->data->user_name), tab[5]);
	tab[6] = ft_max(ft_strlen(ft_itoa(tree->data->links)), tab[6]);
	return (tab);
}
