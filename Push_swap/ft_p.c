/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:15:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 15:17:58 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*tmp;

	tmp = *stack_one;
	*stack_one = (*stack_one)->next;
	tmp->next = *stack_two;
	*stack_two = tmp;
}
