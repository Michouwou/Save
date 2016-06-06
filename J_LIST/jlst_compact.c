/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_compact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:33:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/04 13:56:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_compact(j_list **first_node)
{
    j_list *tmpb;
    j_list *element;
    
    element = *first_node;
    while (element)
    {
        while (element->state && element->previous && !element->previous->state)
        {
            tmpb = element->previous;
            if (tmpb->previous)
                tmpb->previous->next = element;
            if (element->next)
                element->next->previous = tmpb;
            element->previous = tmpb->previous;
            tmpb->previous = element;
            tmpb->next = element->next;
            element->next = tmpb;
            if (!element->previous)
                *first_node = element;
        }
        element = element->next;
    }
}
