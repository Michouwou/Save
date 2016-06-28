/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:48:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 18:04:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack_one, t_stack *stack_two)
{
	t_stack	*tmp;

	tmp = stack_one;
	write(1, "\033[0;32m\nA\033[0;m : ", 17);
	while (tmp)
	{
		write(1, tmp->str_rep, ft_strlen(tmp->str_rep));
		write(1, " ", 1);
		tmp = tmp->next;
	}
	tmp = stack_two;
	write(1, "\033[0;35m\nB\033[0;m : ", 17);
	while (tmp)
	{
		write(1, tmp->str_rep, ft_strlen(tmp->str_rep));
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
