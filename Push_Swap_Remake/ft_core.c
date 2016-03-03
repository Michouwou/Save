/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:33:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/03 14:54:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_sol	*ft_core(t_stack *alpha, t_stack *beta, char *options)
{
	t_sol	*solution;
	int		min;
	int		try;

	while (!ft_is_sorted(alpha) || !ft_is_sorted(beta));
	{
		try = -1;
		min = ft_sol_len(ft_try_ab(alpha, beta));
		while (++try < ft_stack_len(alpha) / 2 - ft_stack_len(beta))
			if (ft_sol_len(ft_atob(alpha, beta, try)) < min)
				min = (ft_sol_len(ft_atob(alpha, beta, try)) * -1);
		try = -1;
		while (++try < ft_stack_len(beta))
			if (ft_sol_len(ft_btoa(alpha, beta, try) < ft_topos(min)))
				min = 0;
		if (min == 0)
			ft_add_sol(solution, ft_pa(beta, alpha));
		else if (min < 0)
			ft_add_sol(solution, ft_pa(alpha, beta));
		else
			ft_add_sol(solution, ft_move(alpha, beta));
	}
	ft_add_num_sol(solution, ft_restack(alpha, beta));
	return (solution);
}
