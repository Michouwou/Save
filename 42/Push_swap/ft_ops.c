/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 14:04:09 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/10 13:38:27 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_stack **stack_one, t_stack **stack_two, int code)
{
	t_stack	*tmp;

	tmp = *stack_two;
	*stack_two = (*stack_two)->next;
	tmp->next = *stack_one;
	*stack_one = tmp;
	if (code == 1)
		write(1, "\nAction : pb", 12);
	if (code == 2)
		write(1, "\nAction : pa", 12);
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

void	ft_s(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
