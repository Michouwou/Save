/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_del_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:49:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:49:22 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

static void decrease(j_list *node)
{
    --(node->list_len);
}

void        jlst_del_node(j_list **first_node, int index)
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    if (!first_node || !*first_node)
        return ;
    tmp = *first_node;
    while (i < index && tmp->next)
    {
        i++;
        tmp = tmp->next;
    }
    if (!tmp)
        return ;
    if (tmp->previous)
        tmp->previous->next = tmp->next;
    if (tmp->next)
        tmp->next->previous = tmp->previous;
    if (tmp->data && tmp->alloc_)
        free(tmp->data);
    if (!tmp->previous)
        *first_node = (*first_node)->next;
    free(tmp);
    jlst_map(*first_node, &decrease);
}
