/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:44:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 18:32:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repush(t_stack **stack_two, t_stack **stack_one, char **sols, int is_ext)
{
	int	i;

	i = 0;
	while (*stack_two)
	{
		ft_p(stack_one, stack_two);
		if (is_ext)
			ft_print_stack(*stack_one, *stack_two, NULL);
		*sols = ft_strjoin_free(*sols, " pa");
	}
}
