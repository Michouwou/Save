/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:33:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:34:11 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_merge(j_list *first_list, j_list *second_list)
{
    j_list  *tmpa;
    j_list  *tmpb;
    j_list  *node;
    
    tmpa = second_list;
    tmpb = first_list;
    while (tmpa)
    {
        while (tmpb->next && tmpb->state)
            tmpb = tmpb->next;
        if (tmpb->next == NULL && tmpb->state)
        {
            node = jlst_nodecpy(tmpa);
            node->previous = tmpb;
            node->next = NULL;
            tmpb->next = node;
        }
        else
        {
            tmpb->data = jlst_datacpy(tmpa);
            tmpb->data_len = tmpa->data_len;
            tmpb->alloc_ = 1;
        }
        tmpa = tmpa->next;
    }
}
