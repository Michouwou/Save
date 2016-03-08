/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:05:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/08 10:49:46 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_circle_check(t_stack *alpha)
{
	int		i;
	int 	j;
	t_stack *tmp;

	i = 0;
	j = 0;
	tmp = alpha;

	while (tmp->next && tmp->element < tmp->next->element && (tmp = tmp->next))
		i++;

	if (i == ft_stack_len(alpha) - 1)
		return (1);
	tmp = tmp->next;


	while (tmp->next && tmp->element < tmp->next->element)
		tmp = tmp->next;

	if (tmp->next || tmp->element > alpha->element)
		return (0);
	tmp = alpha;

	while (tmp->next && j < i && tmp->element < tmp->next->element)
	{
		tmp = tmp->next;
		j++;
	}

	if (j != i)
		return (0);
	return (1);
}
