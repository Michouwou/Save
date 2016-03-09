/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 09:12:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 11:51:50 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_copy(t_stack *alpha)
{
	t_stack	*tmp;
	t_stack	*ret;

	tmp = alpha;
	while (tmp->next)
		tmp = tmp->next;
	ret = NULL;
	while (tmp)
	{
		ft_add_number(&ret, tmp->element);
		tmp = tmp->prev;
	}
	return (ret);
}
