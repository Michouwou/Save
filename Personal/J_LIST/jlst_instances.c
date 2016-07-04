/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_instances.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:30:45 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:31:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

int     jlst_instances(j_list *first_node, void *data, int (*compare_func)(void*, void*))
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    tmp = first_node;
    while (tmp)
    {
        if (!compare_func(tmp->data, data))
            i++;
        tmp = tmp->next;
    }
    return (i);
}
