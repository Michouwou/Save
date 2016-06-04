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
    j_list  *tmp;
    
    tmp = first_node;
    while (tmp && tmp->next)
    {
        if (tmp->state && tmp->next->state && compare_func(tmp->data, tmp->next->data) > 0)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
