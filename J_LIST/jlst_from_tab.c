/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_from_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:28:45 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:29:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

j_list      *jlst_from_tab(void *tab, size_t size, int length)
{
    void    *tmp;
    j_list  *list;
    j_list  *tmp_list;
    
    if (!tab || size < 1 || length < 1)
        return (NULL);
    tmp = tab;
    list = jlst_new(length);
    tmp_list = list;
    while (list && length)
    {
        list->data = tmp;
        list->data_len = size;
        list->state = 1;
        tmp += size;
        list = list->next;
        length--;
    }
    return (tmp_list);
}
