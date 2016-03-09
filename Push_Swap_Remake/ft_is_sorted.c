/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 09:15:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/08 10:48:50 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Cette fonction indique uniquement si la liste passee en argument est triee ou non
 **/

int     ft_is_sorted(t_stack *alpha)
{
	t_stack	*tmp;
	tmp = alpha;

	while (tmp->next)
	{
		if (tmp->element < tmp->next->element)
			tmp = tmp->next;
		else
			return(0);
	}

	return (1);
}
