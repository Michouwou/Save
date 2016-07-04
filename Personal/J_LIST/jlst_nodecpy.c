/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_nodecpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:01:15 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 16:01:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

j_list      *jlst_nodecpy(j_list *to_copy)
{
    j_list  *new_node;
    
    new_node = (j_list*)malloc(sizeof(j_list));
    new_node->data = jlst_datacpy(to_copy);
    new_node->data_len = to_copy->data_len;
    new_node->next = to_copy->next;
    new_node->previous = to_copy->previous;
    new_node->state = to_copy->state;
    new_node->alloc_ = 1;
    return (new_node);
}
