/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 13:52:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 13:59:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *alpha)
{
	if (alpha->len <= 1 || (ft_circular_check(alpha) == 1 &&
			alpha->stack[alpha->len - 1] > alpha->stack[0]))
		return (1);
	return (0);
}
