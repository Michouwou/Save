/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:03:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/23 17:23:39 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normalize(t_stack *alpha, char is_ext)
{
	if (!ft_strcmp(alpha->name, "a"))
		while (!ft_is_sorted(alpha))
		{
			if (ft_middle_coeff(alpha) == 1)
				ft_rrotate(alpha, 'a');
			if (ft_middle_coeff(alpha) == 2)
				ft_rotate(alpha, 'a');
			if (is_ext == 'x')
				ft_printf("Operation de normalisation de a, on fait tourner la 
						pile pour que les elements soient au bon 
						emplacement\n");
		}
	else if (!ft_strcmp(alpha->name, "b"))
		while (!ft_is_sorted(ft_rev_stack(alpha)))
		{
			if (ft_middle_coeff(ft_rev_stack(alpha)) == 1)
				ft_rrotate(alpha, 'a');
			if (ft_middle_coeff(ft_rev_stack(alpha)) == 2)
				ft_rotate(alpha, 'a');
			if (is_ext == 'x')
				ft_printf("Operation de normalisation de b, on fait tourner la 
						pile pour que les elements soient au bon 
						emplacement\n");

		}
}
