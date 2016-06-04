/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_in_jlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:51:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:56:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

int		jlst_in_jlst(j_list *great_list, j_list *to_search, int (*compare_func)(void*, void*))
{
    j_list  *tmpa;
    j_list  *tmpb;
    j_list  *tmpc;
    int     i[2];
    
    tmpa = great_list;
    i[1] = jlst_length(great_list) - jlst_length(to_search);
    i[0] = 0;
    while (tmpa && i[0] <= i[1])
    {
        tmpb = to_search;
        if (!compare_func(tmpa->data, tmpb->data))
        {
            tmpc = tmpa;
            while (tmpc && tmpb && !compare_func(tmpc->data, tmpb->data))
            {
                tmpc = tmpc->next;
                tmpb = tmpb->next;
            }
            if (tmpb == NULL)
                return (i[0]);
        }
        i[0]++;
        tmpa = tmpa->next;
    }
	return (-1);
}
