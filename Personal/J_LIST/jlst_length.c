/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:57:02 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:57:39 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

int     jlst_length(j_list *first_node)
{
    int     i;
    j_list  *tmp;
    
    i = 0;
    tmp = first_node;
    while (tmp)
    {
        ++i;
        tmp = tmp->next;
    }
    return (i);
}
