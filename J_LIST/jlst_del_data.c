/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_del_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:49:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:49:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_del_data(j_list **first_node, void *data, int (*compare_func)(void*, void*), int code)
{
    int     i;
    j_list  *tmp;
    
    i = 1;
    tmp = *first_node;
    while (tmp)
    {
        if (!compare_func(tmp->data, data))
            jlst_del_node(first_node, i, code);
        tmp = tmp->next;
        i++;
    }
}
