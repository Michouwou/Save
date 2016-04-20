/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_widths.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 11:28:18 by mlevieux         ###   ########.fr       */
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
	write(1, "A\n", 2);
	if (tree->right && tree->right->data)
		tab = ft_get_widths(tree->right, tab);
	if (!tab)
		tab = int_tab();
	write(1, "B\n", 2);
	tab[0] = ft_max(ft_strlen(tree->data->name), tab[0]);
	write(1, "C\n", 2);
	tab[1] = WIN_WIDTH / (tab[0] + 1);
	if (ft_strlen(tree->data->date_num) != 0)
		tab[2] = ft_max(ft_strlen(tree->data->date_num), tab[2]);
	write(1, "E\n", 2);
	tab[3] = ft_max(ft_strlen(ft_itoa(tree->data->size)), tab[3]);
	write(1, "F\n", 2);
	tab[4] = ft_max(ft_strlen(tree->data->group_name), tab[4]);
	write(1, "G\n", 2);
	tab[5] = ft_max(ft_strlen(tree->data->user_name), tab[5]);
	write(1, "H\n", 2);
	tab[6] = ft_max(ft_strlen(ft_itoa(tree->data->links)), tab[6]);
	write(1, "I\n", 2);
	return (tab);
}
