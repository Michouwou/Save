/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:04:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 13:46:55 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_cs(t_stack *alpha, t_stack *beta)
{
	int		i;
	double	result;

	i = 1;
	result = 0.0;
	while (i < alpha->len && i < beta->len)
	{
		if (alpha->stack[i - 1] < alpha->stack[i] &&
				beta->stack[i - 1] < beta->stack[i])
			result += 1.0 / ((alpha->len > beta->len) ? beta->len : alpha->len);
		i++;
	}
	return (result);
}

double	ft_cds(t_stack *alpha, t_stack *beta)
{
	int		i;
	int		j;
	double	result;

	i = 1;
	j = 0;
	result = 0.0;
	while (j < alpha->len && beta->stack[0] > alpha->stack[j])
		j++;
	while (i < beta->len)
	{
		while (beta->stack[i] <= alpha->stack[j - 1] && j-- > 0)
			result += 1.0 / (beta->len * (alpha->len / 2));
		while (beta->stack[i] > alpha->stack[j] && j++ < alpha->len)
			result += 1.0 / (beta->len * (alpha->len / 2));
		i++;
	}
	return (result);
}
