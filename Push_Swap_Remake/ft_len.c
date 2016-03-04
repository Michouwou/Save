/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:35:16 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 10:27:39 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_len(t_stack *alpha)
{
	int	i;

	i = 0;
	if (alpha)
	{
		i++;
		alpha = alpha->next;
		while (alpha->first == 0)
		{
			alpha = alpha->next;
			i++;
		}
	}
	return (i);
}

int		ft_sol_len(t_sol *solution)
{
	int i;

	i = 0;
	while (solution != NULL)
	{
		solution = solution->next;
		i++;
	}
	return (i);
}
