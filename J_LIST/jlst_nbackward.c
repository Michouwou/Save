/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlst_nbackward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:00:25 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 16:00:31 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"

void    jlst_nbackward(int n, j_list **first_node)
{
    while (n > 0 && (*first_node)->previous)
    {
        *first_node = (*first_node)->previous;
        --n;
    }
}
