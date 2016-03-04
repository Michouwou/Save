/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:08:02 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 13:01:18 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * La fonction suivante precise dans quel sens il faut faire tourner la liste
 **/

int		ft_direction(t_stack *alpha)
{
	t_stack *tmp;
	int     middle;
	int     cursor;

	printf("Entree dans ft_firection\n");
	fflush(stdout);

	middle = ft_stack_len(alpha);
	tmp = alpha;
	cursor = 0;

	printf("Affectation des differents elements, tmp, middle, cursor, juste avant la boucle\n");
	fflush(stdout);

	while (cursor < middle)
	{
		if (tmp->prev->element > tmp->element &&
				tmp->next->element > tmp->element)
			return (1);
		tmp = tmp->next;
		cursor++;
	}

	printf("On vient de passer la boucle de ft_direction, on va donc renvoyer 0\n");
	fflush(stdout);
	
	return (0);
}
