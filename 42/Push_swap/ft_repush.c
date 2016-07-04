/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:44:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 18:12:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repush(t_stack **stack_t, t_stack **stack_o, char **sols, int is_ext)
{
	int	i;

	i = 0;
	while (*stack_t)
	{
		ft_p(stack_o, stack_t, is_ext ? 2 : 0);
		if (is_ext)
			ft_print_stack(*stack_o, *stack_t);
		*sols = ft_strjoin_free(*sols, " pa");
	}
}
