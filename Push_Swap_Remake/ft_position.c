/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:16:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 17:35:21 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction est sensee renvoyer la position relative du premier element de b
 * par rapport a la pile a
 **/

int		ft_direction(t_stack *alpha, int number)
{
	t_stack	*tmp;
	int		i;

	tmp = alpha;
	i = 0;
	if (number < ft_stack_min(alpha))
	{
		while (tmp->element != ft_stack_min(alpha))
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	while (tmp->next)
	{
		if (number > tmp->element && number < tmp->next->element)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		ft_position(t_stack *alpha)
{
	t_stack	*tmp;
	int		i;
	int		j;
	
	i = 0;
	tmp = alpha;
	while (tmp->next)
	{
		if (tmp->next->element < tmp->element)
			return (i > ft_stack_len(alpha) / 2 ? i - ft_stack_len(alpha) : i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
