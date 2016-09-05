/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_datacpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:01:45 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/04 13:56:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void        *jlst_datacpy(j_list *node)
{
    unsigned char   *data;
    unsigned char   *copy;
    int             i;
    
    data = (unsigned char*)node->data;
    copy = (unsigned char*)malloc(sizeof(unsigned char) * node->data_len);
    i = 0;
    while (i < (int)node->data_len)
    {
        copy[i] = data[i];
        i++;
    }
    return ((void*)copy);
}
