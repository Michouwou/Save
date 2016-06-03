/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_sed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:00:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 16:01:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_sed(j_list *first_node, int code)
{
    j_list      *tmpa;
    j_list      *tmpb;
    
    tmpa = first_node;
    while (tmpa)
    {
        tmpb = tmpa->next;
        while (tmpb && !tmpb->data)
            tmpb = tmpb->next;
        if (tmpb == NULL)
        {
            tmpb = tmpa->next;
            tmpa->next = NULL;
            tmpb->previous = NULL;
            jlst_del_list(tmpb, code);
            return;
        }
        else
            tmpa = tmpa->next;
    }
}
