/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:56:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 14:11:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_cn(t_stack *alpha)
{
	double	result;
	int		i;

	i = 0;
	result = 0.0;
	while (i < alpha->len - 1)
	{
		if (alpha->stack[i] < alpha->stack[i + 1])
			result += 1.0 / alpha->len;
		i++;
	}
	return (result);
}

double	ft_ci(t_stack *alpha)
{
	return (1.0 - ft_cn(alpha));
}
