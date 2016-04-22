/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:23:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:23:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

j_list  *jlst_node(void)
{
    j_list  *new;
    
    new = (j_list*)malloc(sizeof(j_list));
    new->data = NULL;
    new->list_len = 0;
    new->data_len = 0;
    new->previous = NULL;
    new->next = NULL;
    return (new);
}
