/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 11:32:15 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 13:18:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *alpha)
{
	t_stack *tmp;

	tmp = alpha;
	while (tmp)
	{
		printf("\t\tTMP->ELEMENT : %d\n", tmp->element);
		fflush(stdout);
		tmp = tmp->next;
	}
}
