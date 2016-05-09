/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:48:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 18:28:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack_one, t_stack *stack_two, char *action)
{
	t_stack	*tmp;

	tmp = stack_one;
	write(1, "\nA : ", 5);
	while (tmp)
	{
		write(1, tmp->str_rep, ft_strlen(tmp->str_rep));
		write(1, " " , 1);
		tmp = tmp->next;
	}
	tmp = stack_two;
	write(1, "\nB : ", 5);
	while (tmp)
	{
		write(1, tmp->str_rep, ft_strlen(tmp->str_rep));
		write(1, " ", 1);
		tmp = tmp->next;
	}
}
