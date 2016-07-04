/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_get_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:29:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:30:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

int     jlst_get_index(j_list *first_node, void *data, int (*compare_func)(void*, void*))
{
    int     ret;
    j_list  *tmp;
    
    ret = 0;
    tmp = first_node;
    while (tmp)
    {
        if (!compare_func(tmp->data, data))
            break;
        tmp = tmp->next;
        ret++;
    }
    if (tmp == NULL)
        return (-1);
    return (ret);
}
