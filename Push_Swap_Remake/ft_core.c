/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:33:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/08 15:44:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * La fonction suivante est la fonction de traitement, c'est elle aui assure
 * la somme des minima locaux pour atteindre le chemin le plus court
 **/

static void ft_alpha(t_stack **alpha, t_stack **beta, t_sol **solution, int *min_max_med)
{
	int		i;

	if ((*alpha)->element > (*alpha)->next->element && (*alpha)->next->next && (*alpha)->next->next->element > (*alpha)->element)
		ft_add_sol(solution, ft_sa(alpha));
	else if ((*alpha)->element < min_max_med[2])
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
	if (ft_circle_check(*alpha) && !ft_is_sorted(*alpha))
		ft_add_sol(solution, ft_ra(alpha));

}
static void ft_beta(t_stack **alpha, t_stack **beta, t_sol **solution)
{
	int	min_max[2];
	int i;

	min_max[0] = ft_stack_min(*beta);
	min_max[1] = ft_stack_max(*beta);
	if ((*beta)->element == min_max[0])
		ft_add_sol(solution, ft_ra(beta));
	else if ((*beta)->element < (*beta)->next->element)
		ft_add_sol(solution, ft_sa(beta));
	else
	{
		i = ft_bposition(*beta);
		if (i < 0)
			while (i++)
				ft_add_sol(solution, ft_rra(beta));
		if (i > 0)
			while (i--)
				ft_add_sol(solution, ft_ra(beta));
	}
}
void ft_core(t_stack **alpha, t_stack **beta, t_sol **solution, char *options)
{
	int		min_max_med[3];
	int i;

	min_max_med[0] = ft_stack_min(*alpha);
	min_max_med[1] = ft_stack_max(*alpha);
	min_max_med[2] = ft_stack_med(*alpha);

	i = 0;
	while (!ft_is_sorted(*alpha))
	{
		ft_print_stack(*alpha);
		ft_alpha(alpha, beta, solution, min_max_med);
		if (*beta && (*beta)->next)
			ft_beta(alpha, beta, solution);
	}
}
