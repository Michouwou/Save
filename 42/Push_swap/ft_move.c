/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:44:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 18:12:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_stack **stack, t_stack *stack_two, int dir_ind[], char **sols)
{
	int	i;

	i = 0;
	if (dir_ind[0] % 10 == 1)
		while ((*stack)->index != dir_ind[1])
		{
			ft_r(stack);
			*sols = ft_strjoin_free(*sols, " ra");
			if (dir_ind[0] > 10)
			{
				write(1, "\nAction : ra", 12);
				ft_print_stack(*stack, stack_two);
			}
		}
	else
		while ((*stack)->index != dir_ind[1])
		{
			ft_rr(stack);
			*sols = ft_strjoin_free(*sols, " rra");
			if (dir_ind[0] > 10)
			{
				write(1, "\nAction : rra", 13);
				ft_print_stack(*stack, stack_two);
			}
		}
}
