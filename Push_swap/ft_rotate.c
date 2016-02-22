/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:06:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 14:20:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *alpha)
{
	int i;
	int tmp;

	i = 1;
	tmp = alpha->stack[0];
	while (i < alpha->len)
	{
		alpha->stack[i - 1] = alpha->stack[i];
		i++;
	}
	alpha->stack[alpha->len - 1] = tmp;
}

void	ft_drotate(t_stack *alpha, t_stack *beta)
{
	ft_rotate(alpha);
	ft_rotate(beta);
}

void	ft_rrotate(t_stack *alpha)
{
	int i;
	int tmp;

	i = alpha->len - 1;
	tmp = alpha->stack[alpha->len - 1];
	while (i > 0)
	{
		alpha->stack[i] = alpha->stack[i - 1];
		i--;
	}
	alpha->stack[0] = tmp;
}

void	ft_drrotate(t_stack *alpha, t_stack *beta)
{
	ft_rrotate(alpha);
	ft_rrotate(beta);
}
