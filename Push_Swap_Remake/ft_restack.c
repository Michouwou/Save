/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:25:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 12:14:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction remet b sur a, normalement uniquement lorsque les deux sont triees
 * dans leur ordre respectif
 **/

t_sol	*ft_restack(t_stack *alpha, t_stack *beta)
{
	t_sol	*solution;
	t_stack *tmp;

	printf("Entree dans ft_restack\n");
	fflush(stdout);

	while (beta)
	{
		tmp = alpha;
		while (tmp->next)
			tmp = tmp->next;
		if (beta->element < alpha->element && (tmp->element < beta->element ||
				tmp->element > alpha->element))
			ft_add_sol(&solution, ft_pa(&beta, &alpha));
		else if (beta->element < alpha->element)
			ft_add_sol(&solution, ft_rra(&alpha));
		else if (beta->element > alpha->element && beta->element < tmp->element)
			ft_add_sol(&solution, ft_ra(&alpha));
		else if (beta->element > alpha->element && beta->element > tmp->element)
		{
			ft_add_sol(&solution, ft_pa(&beta, &alpha));
			ft_add_sol(&solution, ft_ra(&alpha));
		}
	}

	printf("Sortie de la boucle de restack, tout s'est bien passe?\n");
	fflush(stdout);

	return (solution);
}
