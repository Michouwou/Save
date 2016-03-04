/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 11:39:29 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_is_sorted(t_stack *alpha)
{
	t_stack	*tmp;
	tmp = alpha->next;
	while (tmp->next->first == 0)
	{
		ft_print_stack(alpha);
		if (tmp->prev->element < tmp->element && tmp->element < tmp->next->element)
			tmp = tmp->next;
		else
			return(0);
	}
	printf("On est bon la? (is_sorted), nom de la pile : %s\n", alpha->name);
	fflush(stdout);
	return (1);
}
