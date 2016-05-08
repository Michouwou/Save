/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 14:04:09 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 14:26:41 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*tmp;

	tmp = *stack_two;
	*stack_two = (*stack_two)->next;
	tmp->next = *stack_one;
	*stack_one = tmp;
}

void	ft_r(t_stack **stack)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *stack;
	tmpb = (*stack)->next;
	*stack = (*stack)->next;
	while (tmpb->next)
		tmpb = tmpb->next;
	tmpb->next = tmpa;
	tmpa->next = NULL;
}

void	ft_rr(t_stack **stack)
{
	t_stack	*tmpa;
	t_stack *tmpb;

	tmpa = *stack;
	while (tmpa->next->next)
		tmpa = tmpa->next;
	tmpb = tmpa->next;
	tmpa->next = NULL;
	tmpb->next = *stack;
	*stack = tmpb;
}
