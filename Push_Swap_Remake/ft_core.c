/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:33:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 16:05:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * La fonction suivante est la fonction de traitement, c'est elle aui assure
 * la somme des minima locaux pour atteindre le chemin le plus court
 **/


void ft_core(t_stack **alpha, t_stack **beta, t_sol **solution, char *options)
{
	int		min_max_med[3];
	int		i;

	printf("Nous venons d'entrer dans ft_core, les piles valent:\n");
	ft_print_stack(*alpha);
	printf("\n");
	ft_print_stack(*beta);
	printf("\n");
	fflush(stdout);
	min_max_med[0] = ft_stack_min(*alpha);
	min_max_med[1] = ft_stack_max(*alpha);
	min_max_med[2] = ft_stack_med(*alpha);

	while (!ft_is_sorted(*alpha) || !ft_is_sorted(*beta))
	{
		if ((*alpha)->element < min_max_med[2])
			ft_add_sol(solution, ft_pa(alpha, beta));
		else if ((*alpha)->element == min_max_med[1])
			ft_add_sol(solution, ft_ra(alpha));
		else if ((*alpha)->element > (*alpha)->next->element)
			ft_add_sol(solution, ft_sa(alpha));
		else
		{
			i = ft_position(*alpha);
			if (i < 0)
				while (i++)
					ft_add_sol(solution, ft_rra(alpha));
			if (i > 0)
				while (i--)
					ft_add_sol(solution, ft_ra(alpha));
		}
		if (ft_circle_check(*alpha))
			ft_add_sol(solution, ft_ra(alpha));
	}
}
