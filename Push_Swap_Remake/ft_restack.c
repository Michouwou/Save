/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:25:10 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 17:29:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction remet b sur a, normalement uniquement lorsque les deux sont triees
 * dans leur ordre respectif
 **/

t_sol	*ft_restack(t_stack **alpha, t_stack **beta)
{
	t_sol	*solution;

	printf("Entree dans ft_restack\n");
	fflush(stdout);
	
	solution = NULL;
	while (*beta)
	{
		if (ft_direction(*alpha, (*beta)->element) > ft_stack_len(*alpha) / 2)
			ft_add_sol(&solution, ft_rra(alpha));
		else if (ft_direction(*alpha, (*beta)->element) > 0)
			ft_add_sol(&solution, ft_ra(alpha));
		else if (ft_direction(*alpha, (*beta)->element) == 0)
		{
			ft_add_sol(&solution, ft_ra(alpha));
			ft_add_sol(&solution, ft_pa(beta, alpha));
		}
	}
	while (!ft_is_sorted(*alpha))
	{
		if (ft_position(*alpha))
			ft_add_sol(&solution, ft_rra(alpha));
		else
			ft_add_sol(&solution, ft_ra(alpha));
	}
	printf("Sortie de la boucle de restack, tout s'est bien passe?\n");
	ft_display(solution, ft_strnew(5));
	fflush(stdout);

	return (solution);
}
