/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_extrema.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:50:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 14:03:40 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_max(t_stack *alpha)
{
	int		max;
	t_stack	*tmp;
	
	max = -2147483648;
	tmp = alpha;
	while (tmp)
	{
		if (tmp->element > max)
			max = tmp->element;
		tmp = tmp->next;
	}
	return (max);
}

int		ft_stack_min(t_stack *alpha)
{
	int		min;
	t_stack	*tmp;

	min = 2147483647;
	tmp = alpha;
	while (tmp)
	{
		if (tmp->element < min)
			min = tmp->element;
		tmp = tmp->next;
	}
	return (min);
}
