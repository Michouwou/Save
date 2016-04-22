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
    int     i;
    j_list  *tmpa;
    j_list  *tmpb;
    j_list  *node;
    
    tmpa = second_list;
    while (tmpa)
    {
        tmpb = first_list;
        i = 0;
        while (tmpb->next && tmpb->data)
            tmpb = tmpb->next;
        if (tmpb->next == NULL && tmpb->data)
        {
            node = jlst_nodecpy(tmpa);
            node->previous = tmpb;
            node->next = NULL;
            tmpb->next = node;
        }
        else
        {
            tmpb->data = jlst_datacpy(tmpa);
            tmpb->data_len = sizeof(tmpb->data);
        }
        tmpa = tmpa->next;
    }
}
