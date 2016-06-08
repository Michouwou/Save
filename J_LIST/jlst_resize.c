/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:57:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:58:03 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_resize(j_list *first_node)
{
    j_list  *tmp;
    j_list  *node;

    tmp = first_node;
    while (tmp)
    {
        node = jlst_node();
        node->next = tmp->next;
        node->previous = tmp;
        tmp->next = node;
        tmp = tmp->next->next;
    }
}
