/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_get_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:29:26 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:29:42 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    *jlst_get_data(j_list *first_node, int index)
{
    int     i;
    j_list  *list;
    
    i = 0;
    list = first_node;
    while (list && i < index)
    {
        list = list->next;
        i++;
    }
    return (i == index ? list->data : NULL);
}
