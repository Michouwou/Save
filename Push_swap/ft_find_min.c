/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:26:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 09:29:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_min(t_stack *alpha)
{
	int i;
	int j;

	i = 1;
	j = alpha->stack[0];
	while(i < alpha->len)
	{
		if (alpha->stack[i] < j)
			j = alpha->stack[i];
		i++;
	}
	return (j);
}

int		ft_find_max(t_stack *alpha)
{
	int i;
	int j;

	i = 1;
	j = alpha->stack[0];
	while(i < alpha->len)
	{
		if (alpha->stack[i] > j)
			j = alpha->stack[i];
		i++;
	}
	return (j);
}
