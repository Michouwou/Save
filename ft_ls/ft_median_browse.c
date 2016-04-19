/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_browse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/19 13:52:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_median_browse(t_tree *tree, int *flag)
{
	if (flag[0])
	{
		if (tree->left)
		{
			ft_median_browse(tree->left, flag);
			ft_free_tree(tree->left);
		}
		if (tree->data->is_dir && !(flag[4] && tree->data->name[0] == '.') &&
				ft_strcmp(tree->data->name, ft_strdup(".")) &&
				ft_strcmp(tree->data->name, ft_strdup("..")))
		{
			ft_printf("%s :\n", tree->data->path);
			ft_browse(tree->data->path, flag);
		}
		if (tree->right)
		{
			ft_median_browse(tree->right, flag);
			ft_free_tree(tree->right);
		}
	}
}
