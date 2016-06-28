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
    
    new = NULL;
    if (!first_node)
        return ;
    while (*first_node)
    {
        tmp = *first_node;
        min_e = tmp;
        while (tmp)
        {
            if (compare_func(tmp->data, min_e->data) > 0)
                min_e = tmp;
            tmp = tmp->next;
        }
        jlst_push_front(&new, jlst_datacpy(min_e), min_e->data_len, 1);
        jlst_del_node(first_node, jlst_get_index(*first_node, min_e->data, compare_func));
    }
    *first_node = new;
}