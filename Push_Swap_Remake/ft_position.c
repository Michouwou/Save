/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:16:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 17:26:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_position(t_stack *beta, t_stack *alpha)
{
	t_stack	*tmp;
	t_stack	*ctmp;
	int		middle;
	int		cursor;

	middle = ft_stack_len(alpha);
	tmp = alpha;
	ctmp = alpha;
	cursor = 0;
	while (cursor < middle)
	{
		if (tmp->element > beta->element &&
			tmp->prev->element < beta->element)
			return (1);
		if (ctmp->element > beta->element &&
			ctmp->prev->element < beta->element)
			return (0);
		tmp = tmp->next;
		ctmp = ctmp->prev;
		cursor++;
	}
	return (0);
}
