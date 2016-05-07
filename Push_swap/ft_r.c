/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:51:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 14:55:30 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_stack **stack)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *stack;
	*stack = (*stack)->next;
	tmpa->next = NULL;
	tmpb = (*stack);
	while (tmpb && tmpb->next)
		tmpb = tmpb->next;
	tmpb->next = tmpa;
}
