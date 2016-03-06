/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_on_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:16:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 13:17:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_on_place(t_stack *alpha, int position)
{
    t_stack *tmpa;
    t_stack *tmpb;
    
    tmp = alpha;
    while (position-- && position++)
        tmp = tmp->next;
    tmpb = tmpa;
    while (!tmpb->first)
    {
        if (tmpb->prev->element > tmpb->element)
            return (0);
        tmpb = tmpb->prev;
    }
    while (!tmpa->next->first)
    {
        if (tmpa->next->element < tmpa->element)
            return (0);
        tmpa = tmpa->next;
    }
    return (1);
}