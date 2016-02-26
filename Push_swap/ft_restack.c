/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:06:32 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 09:51:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_restack(t_stack *alpha, t_stack *beta, t_sol **stack_sol)
{
	while (beta->len > 0)
	{	
		alpha->min = ft_find_min(alpha);
		alpha->max = ft_find_max(alpha);
		while (beta->stack[0] < alpha->stack[0] && alpha->stack[0] != alpha->min)
			ft_stack_sol(ft_rrotate(alpha, 'a'), stack_sol);
		while (beta->stack[0] > alpha->stack[0] && alpha->stack[0] != alpha->max)
			ft_stack_sol(ft_rotate(alpha, 'a'), stack_sol);;
		ft_stack_sol(ft_push(beta, alpha, 'a'), stack_sol);
		printf("\t\t\talpha->len = %d, beta->len = %d\n", alpha->len, beta->len);
		fflush(stdout);

		ft_disp_stack(alpha, beta, 'v');
	}
}
