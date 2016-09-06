/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:58:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:58:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

int     jlst_is_sorted(j_list *first_node, int (*compare_func)(void*, void*))
{
    j_list  *tmpa;
    j_list	*tmpb;
    
    tmpa = first_node;
    while (tmpa && tmpa->next)
    {
    	if (tmpa->state)
    	{
        	tmpb = tmpa->next;
        	while (tmpb && !tmpb->state)
        		tmpb = tmpb->next;
        	if (!tmpb)
        		return (1);
        	else if (tmpb && compare_func(tmpa->data, tmpb->data) > 0)
        		return (0);
    	}
    	tmpa = tmpa->next;
    }
    return (1);
}
