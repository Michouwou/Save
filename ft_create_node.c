/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:58:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_tree      *ft_create_node(void)
{
    t_tree  *new;
    
    new = (t_data*)malloc(sizeof(t_data));
    new->data = NULL;
    new->right = NULL;
    new->left = NULL;
    return (new);
}