/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doubles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:20:56 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/14 12:13:39 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_doubles(t_stack **first, int is_stat)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *first;
	while (tmpa && tmpa->next)
	{
		tmpb = tmpa->next;
		while (tmpb)
		{
			if (tmpb->number == tmpa->number)
			{
				if (!is_stat)
					ft_error(2, tmpb->str_rep);
				ft_error_loop(2, tmpb->str_rep);
				//ft_free(*first);
				//*first = NULL;
			}
			tmpb = tmpb->next;
		}
		tmpa = tmpa->next;
	}
}
