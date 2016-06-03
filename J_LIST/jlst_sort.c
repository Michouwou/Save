/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:31:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:32:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_sort(j_list **first_node, int (*compare_func)(void*, void*))
{
    j_list  *tmp;
    j_list  *min_e;
    j_list  *new;
    
    new = jlst_new(1);
    while (*first_node)
    {
        tmp = *first_node;
        min_e = tmp;
        while (tmp)
        {
            if (compare_func(tmp->data, min_e->data) < 0)
                min_e = tmp;
            tmp = tmp->next;
        }
        if (min_e->previous == NULL && (*first_node)->next)
            *first_node = (*first_node)->next;
        jlst_push_back(&new, min_e->data, min_e->data_len);
        jlst_del_data(first_node, min_e->data, compare_func);
    }
    jlst_del_list(*first_node);
    *first_node = new;
}
