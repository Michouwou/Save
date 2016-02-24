/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:00:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 09:29:18 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_core(char **argv, int argc)
{
	t_sol	*sols;
	char	*options;
	t_stack	*alpha;
	t_stack	*beta;

	sols = ft_create_sol();
	options = ft_extract_options(argv, argc);
	alpha = ft_fill_stack(argv, argc, options);
	beta = ft_new_stack();
	alpha->name = ft_strcpy(alpha->name, "a");
	beta->name = ft_strcpy(beta->name, "b");
	ft_divide(alpha, beta, options);
	while (!ft_circular_check(alpha) || !ft_circular_check(ft_rev_stack(beta)))
		ft_stack_sol(ft_next_op(alpha, beta, ft_coeffs(alpha, beta), sols));
	ft_normalize(alpha);
	ft_normalize(beta);
	ft_restack(alpha, beta);
	ft_display(options, sols);
}
