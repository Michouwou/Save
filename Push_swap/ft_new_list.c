/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:18:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/07 15:22:30 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_list(void)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->next = NULL;
	new->number = 0;
	new->index = 0;
	return (new);
}
