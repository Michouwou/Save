/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_get_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:30:21 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:30:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

int     jlst_get_size(j_list *first_node)
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    tmp = first_node;
    while (tmp)
    {
        if (tmp->state)
            i++;
        tmp = tmp->next;
    }
    return (i);
}
