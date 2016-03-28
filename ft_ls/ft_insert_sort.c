/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:58:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * flag vaudra 1 si l'option -t est specifiee, 0 sinon
**/

void    ft_insert_sort(t_data *data, t_tree **first, int flag)
{
    t_tree  *new;
    t_tree  *tmp;
    
    new = ft_create_node();
    new->data = data;
    tmp = *first;
    while (tmp && (tmp->right || tmp->left))
    {
        if (((ft_strcmp(tmp->data->name, new->data->name) > 0 && !flag) ||
            ((tmp->data->name - new->data->name) > 0 && flag)) && tmp->left)
            tmp = tmp->left;
        else if (((ft_strcmp(tmp->data->name, new->data->name) < 0 && !flag) ||
            ((tmp->data->name - new->data->name) =< 0 && flag)) && tmp->right)
            tmp = tmp->right;
        else
            break;
    }
    if (tmp && (ft_strcmp(tmp->data->name, new->data->name) > 0 && !flag) ||
        ((tmp->data->name - new->data->name) > 0 && flag))
        tmp->left = new;
    else if (tmp && (ft_strcmp(tmp->data->name, new->data->name) < 0 && !flag) ||
        ((tmp->data->name - new->data->name) =< 0 && flag))
        tmp->right = new;
    else
        tmp = new;
}