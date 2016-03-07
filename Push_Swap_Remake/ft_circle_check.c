/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:05:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 14:46:07 by mlevieux         ###   ########.fr       */
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

	printf("Entree circle_check\n");
	fflush(stdout);

	while (tmp->next && tmp->element < tmp->next->element && (tmp = tmp->next))
		i++;

	printf("i = %d\n", i);
	fflush(stdout);

	if (i == ft_stack_len(alpha) - 1)
		return (1);
	tmp = tmp->next;

	printf("On ne s'est pas arrete apres i?\n");
	fflush(stdout);

	while (tmp->next && tmp->element < tmp->next->element)
		tmp = tmp->next;

	printf("Alors ca plante au niveau de l'avancee jusqu'a la fin\n");
	fflush(stdout);

	if (tmp->next)
		return (0);
	tmp = alpha;

	printf("Avant la boucle du j, j vaut = %d\n", j);
	fflush(stdout);

	while (tmp->next && j < i && tmp->element < tmp->next->element)
	{
		tmp = tmp->next;
		j++;
	}

	printf("Et la j vaut = %d\n", j);
	fflush(stdout);

	if (j != i)
		return (0);
	return (1);
}
