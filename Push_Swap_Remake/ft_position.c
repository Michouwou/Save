/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:16:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 13:17:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction est sensee renvoyer la position relative du premier element de b
 * par rapport a la pile a
 **/

int		ft_position(t_stack *beta, t_stack *alpha)
{
	t_stack	*tmp;
	t_stack	*ctmp;
	int		middle;
	int		cursor;

	printf("Entree dans ft_position\n");
	fflush(stdout);

	middle = ft_stack_len(alpha);
	tmp = alpha;
	ctmp = alpha;
	cursor = 0;

	printf("Affectation des elements middle, tmp, ctmp, cursor\n");
	fflush(stdout);

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

	printf("Sortie de position, on va renvoyer 0\n");
	fflush(stdout);

	return (0);
}
