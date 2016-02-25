/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:03:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 17:19:29 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalize(t_stack *alpha, char is_ext, t_sol **sols)
{
	if (!ft_strcmp(alpha->name, "a"))
		while (!ft_is_sorted(alpha))
		{
			if (ft_middle_coeff(alpha) == 1)
				ft_stack_sol(ft_rrotate(alpha, 'a'), sols);
			if (ft_middle_coeff(alpha) == 2)
				ft_stack_sol(ft_rotate(alpha, 'a'), sols);
			if (is_ext == 'x')
				ft_printf("Operation de normalisation de a, on fait tourner la pile pour que les elements soient au bon emplacement\n");
			printf("a : %d, %d, %d\n", alpha->stack[0], alpha->stack[1], alpha->stack[2]);
			printf("Is a sorted? %s\n", ft_is_sorted(alpha) ? "Yes" : "No");
			fflush(stdout);
		}
	else if (!ft_strcmp(alpha->name, "b"))
		while (!ft_is_sorted(ft_rev_stack(alpha)))
		{
			if (ft_middle_coeff(ft_rev_stack(alpha)) == 1)
				ft_stack_sol(ft_rrotate(alpha, 'a'), sols);
			if (ft_middle_coeff(ft_rev_stack(alpha)) == 2)
				ft_stack_sol(ft_rotate(alpha, 'a'), sols);
			if (is_ext == 'x')
				ft_printf("Operation de normalisation de b, on fait tourner la pile pour que les elements soient au bon emplacement\n");
			break;
		}
}
