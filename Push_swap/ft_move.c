/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:44:43 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 17:47:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_stack **stack, int direction, int index, char **sols)
{
	int	i;

	i = 0;
	if (direction % 10 == 1)
		while ((*stack)->index != index)
		{
			ft_r(stack);
			*sols = ft_strjoin_free(*sols, " ra");
			if (direction > 10)
				ft_print_stack(*stack, NULL, "ra");
		}
	else
		while ((*stack)->index != index)
		{
			ft_rr(stack);
			*sols = ft_strjoin_free(*sols, " rra");
			if (direction > 10)
				ft_print_stack(*stack, NULL, "rra");
		}
}
