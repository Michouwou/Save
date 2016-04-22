/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/21 11:14:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_tree(t_tree *tree, int *flag, int *widths)
{
	ft_printf("\033[0;33mHI\033[0;m");
    if ((tree->left && !flag[3]) || (tree->right && flag[3]))
        ft_print_tree(flag[3] ? tree->right : tree->left, flag, widths);
	ft_printf("\033[0;31m%d%d%d%d%d\033[0;m", flag[0], flag[1], flag[2], flag[3], flag[4]);	
    if (flag[2])
        ft_print_list(tree, widths);
    else
        ft_simple_print(tree, widths);
	ft_printf("\033[0;32mPLOP\033[0;m");	
    if ((tree->right && !flag[3]) || (tree->left && flag[3]))
        ft_print_tree(flag[3] ? tree->left : tree->right, flag, widths);
}
