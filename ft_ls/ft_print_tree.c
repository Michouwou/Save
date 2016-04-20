/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 10:12:31 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_tree(t_tree *tree, int *flag, int *widths)
{
    if ((tree->left && !flag[3]) || (tree->right && flag[3]))
        ft_print_tree(flag[3] ? tree->right : tree->left, flag, widths);
	
    if (flag[2])
        ft_print_list(tree, widths);
    else
        ft_simple_print(tree, widths);
    if ((tree->right && !flag[3]) || (tree->left && flag[3]))
        ft_print_tree(flag[3] ? tree->left : tree->right, flag, widths);
}
