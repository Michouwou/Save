/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:08:02 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 11:55:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_direction(t_stack *alpha)
{
	t_stack *tmp;
	int     middle;
	int     cursor;

	middle = ft_stack_len(alpha);
	tmp = alpha;
	cursor = 0;
	while (cursor < middle)
	{
		if (tmp->prev->element > tmp->element &&
				tmp->next->element > tmp->element)
			return (1);
		tmp = tmp->next;
		cursor++;
	}
	printf("Who\n");
	ft_print_stack(alpha);
	fflush(stdout);
	return (0);
}
