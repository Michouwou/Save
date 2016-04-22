/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_del_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:50:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:50:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_del_list(j_list *first_node)
{
    while (first_node)
        jlst_del_node(&first_node, 1);
    free(first_node);
	first_node = NULL;
}
