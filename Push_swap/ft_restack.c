/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:06:32 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 12:17:41 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_restack(t_stack *alpha, t_stack *beta)
{
	while (beta->len > 0)
	{
		while (beta->stack[0] < alpha->stack[0])
			if (alpha->stack[0] != alpha->min)
				ft_rrotate(alpha, 'a');
		while (beta->stack[0] > alpha->stack[0])
			if (alpha->stack[0] != alpha->max)
				ft_rotate(alpha, 'a');
		ft_push(beta, alpha, 'a');
		beta->len--;
		alpha->len++;
	}
}
