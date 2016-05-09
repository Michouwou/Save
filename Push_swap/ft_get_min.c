/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:05:59 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 11:06:01 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min(t_stack *stack)
{
	t_stack			*tmp;
	int				ret;
	long int		tmpi;

	tmp = stack;
	tmpi = LONG_MAX;
	while (tmp)
	{
		if (tmp->number < tmpi)
		{
			tmpi = tmp->number;
			ret = tmp->index;
		}
		tmp = tmp->next;
	}
	return (ret);
}
