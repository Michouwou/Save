/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 09:15:50 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_is_sorted(t_stack *alpha)
{
    alpha = alpha->next;
    while (alpha->first == 0 && alpha->previous->first == 0)
    {
        if (alpha->previous->number < alpha->number && > alpha->next->number)
            alpha = alpha->next->next;
        else
            break;
    }
    if (alpha->first == 0 && alpha->previous->first == 0)
        return (0);
    return (1);
}
