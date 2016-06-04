/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_nforward.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:59:11 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 15:59:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_nforward(int n, j_list **first_node)
{
    while (n > 0 && (*first_node)->next)
    {
        *first_node = (*first_node)->next;
        --n;
    }
}
