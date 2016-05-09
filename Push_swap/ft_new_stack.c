/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:37:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 11:41:01 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int num, int index)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->number = num;
	new->index = index;
	new->str_rep = ft_itoa(num);
	new->next = NULL;
	return (new);
}
