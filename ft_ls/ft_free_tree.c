/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/19 12:14:29 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_free_tree(t_tree *tree)
{
    free(tree->data->mode);
    free(tree->data->date_mon);
    free(tree->data->date_num);
    free(tree->data->date_hour);
    free(tree->data->group_name);
    free(tree->data->user_name);
    free(tree->data->path);
    free(tree->data);
    free(tree);
}
