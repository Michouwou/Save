/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_compact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:33:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:33:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_compact(j_list *first_node)
{
    j_list *tmpa;
    j_list *tmpb;
    j_list *element;
    
    element = first_node;
    while (element)
    {
        tmpa = element;
        while (tmpa->previous && !tmpa->previous->data)
        {
            tmpb = tmpa->previous;
            tmpa->next = tmpb;
            tmpa->previous = tmpb->previous;
            tmpb->previous = tmpa;
            tmpb->next = tmpa->next;
        }
        element = element->next;
    }
}
