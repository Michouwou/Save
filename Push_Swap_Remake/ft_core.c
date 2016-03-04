/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:33:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 12:57:10 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * La fonction suivante est la fonction de traitement, c'est elle aui assure
 * la somme des minima locaux pour atteindre le chemin le plus court
 **/


t_sol	*ft_core(t_stack *alpha, t_stack *beta, char *options)
{
	t_sol	*solution;
	int		min;
	int		try;

	printf("Nous venons d'entrer dans ft_core, les piles valent:\n");
	ft_print_stack(alpha);
	printf("\n");
	ft_print_stack(beta);
	printf("\n");
	fflush(stdout);

	while (!ft_is_sorted(alpha) || !ft_is_sorted(beta))
	{
		try = -1;
		min = ft_sol_len(ft_try_ab(alpha, beta));

		printf("Min vient d'etre calcule\n");
		fflush(stdout);

		while (++try < ft_stack_len(alpha) / 2 - ft_stack_len(beta))
			if (ft_sol_len(ft_atob(alpha, beta, try)) < min)
				min = (ft_sol_len(ft_atob(alpha, beta, try)) * -1);
		
		printf("On vient d'essayer en transferant a vers b\n");
		fflush(stdout);

		try = -1;
		while (++try < ft_stack_len(beta))
			if (ft_sol_len(ft_btoa(alpha, beta, try)) < (min < 0) ? -min : min)
				min = 0;

		printf("On vient d'essayer en transferant b vers a\n");
		fflush(stdout);

		if (min == 0)
			ft_add_sol(solution, ft_pa(beta, alpha));
		else if (min < 0)
			ft_add_sol(solution, ft_pa(alpha, beta));
		else
			ft_add_sol(solution, ft_move(alpha, beta));

		printf("on vient d'ajouter le minimum local a la liste\n");
		fflush(stdout);
	
	}
	return (solution);
}
