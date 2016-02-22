/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:00:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 14:13:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_core(char **argv, int argc)
{
	char	**sols;
	char	*options;
	t_stack	*alpha;
	t_stack	*beta;

	sols = ft_create_sol();
	options = ft_extract_options(argv, argc);
	alpha = ft_fill_stack(argv, argc, options);
	beta = ft_new_stack();
	while (ft_cn(alpha) != 1 || alpha->len != argc - ft_strlen(options))
		ft_stack_sol(ft_next_op(alpha, beta, ft_coeffs(alpha, beta), options));
	ft_display(options, sols);
}
