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

void    jlst_resize(j_list **first_node, int code)
{
    int     i;
    j_list  *new_list;
    j_list  *tmpa;
    j_list  *tmpb;
    
    new_list = jlst_new(2 * jlst_length(*first_node));
    i = 0;
    tmpa = *first_node;
    tmpb = new_list;
    while (tmpa)
    {
        if (!(i % 2))
        {
            tmpb->data = jlst_datacpy(tmpa);
            tmpb->data_len = tmpa->data_len;
            tmpb->state = 1;
            tmpa = tmpa->next;
        }
        i++;
        tmpb = tmpb->next;
    }
    printf("On y est???\n\n");
    jlst_del_list(*first_node, code);
    *first_node = new_list;
}
