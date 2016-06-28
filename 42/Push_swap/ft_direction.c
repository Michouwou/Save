/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:03:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/10 17:03:50 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_direction(t_stack *stack, int index)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp && tmp->index != index)
	{
		++i;
		tmp = tmp->next;
	}
	while (tmp)
	{
		--i;
		tmp = tmp->next;
	}
	if (i < 0)
		return (1);
	else
		return (2);
}
