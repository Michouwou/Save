/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:03:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 14:18:57 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalize(t_stack *alpha, char is_ext, t_sol **sols)
{
	int i;

	i = 0;
	if (!ft_strcmp(alpha->name, "a"))
		while (!ft_is_sorted(alpha) && i++ < 10)
		{
			if (ft_middle_coeff(alpha) == 1)
				ft_stack_sol(ft_rrotate(alpha, 'a'), sols);
			if (ft_middle_coeff(alpha) == 2)
				ft_stack_sol(ft_rotate(alpha, 'a'), sols);
			if (is_ext == 'x')
				ft_printf("Operation de normalisation de a, on fait tourner la pile pour que les elements soient au bon emplacement\n");
			printf("a : %d\n", ft_middle_coeff(alpha));
			printf("Is a sorted? %s\n", ft_is_sorted(alpha) ? "Yes" : "No");
			fflush(stdout);
		}
	else if (!ft_strcmp(alpha->name, "b"))
		while (!ft_is_sorted(ft_rev_stack(alpha)) && i++ < 10)
		{
			if (ft_middle_coeff(ft_rev_stack(alpha)) == 1)
				ft_stack_sol(ft_rrotate(alpha, 'a'), sols);
			if (ft_middle_coeff(ft_rev_stack(alpha)) == 2)
				ft_stack_sol(ft_rotate(alpha, 'a'), sols);
			if (is_ext == 'x')
				ft_printf("Operation de normalisation de b, on fait tourner la pile pour que les elements soient au bon emplacement\n");
		}
}
