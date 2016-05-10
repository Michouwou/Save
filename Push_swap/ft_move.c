/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:44:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/10 13:42:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_stack **stack, t_stack *stack_two, int direction, int index, char **sols)
{
	int	i;

	i = 0;
	if (direction % 10 == 1)
		while ((*stack)->index != index)
		{
			ft_r(stack);
			*sols = ft_strjoin_free(*sols, " ra");
			if (direction > 10)
			{
				write(1, "\nAction : ra", 12);
				ft_print_stack(*stack, stack_two, "ra");
			}
		}
	else
		while ((*stack)->index != index)
		{
			ft_rr(stack);
			*sols = ft_strjoin_free(*sols, " rra");
			if (direction > 10)
			{
				write(1, "\nAction : rra", 13);
				ft_print_stack(*stack, stack_two, "rra");
			}
		}
}
