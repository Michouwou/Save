/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:34:38 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/23 16:56:25 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_disp_stack(t_stack *alpha, t_stack *beta, char is_ext)
{
	int i;

	i = 0;
	if (is_ext == 'v' || is_ext == 'x')
	{
		ft_printf("\ta : ");
		while (i < alpha->len - 1)
			ft_printf("%d ", alpha->stack[i++]);
		ft_printf("%d\n\tb : ", alpha->stack[i]);
		i = 0;
		while (i < beta->len - 1)
			ft_printf("%d ", alpha->stack[i++]);
		ft_printf("%d\n", alpha->stack[i]);
	}
}
