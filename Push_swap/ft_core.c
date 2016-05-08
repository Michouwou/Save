/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 10:32:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 10:45:43 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_core(t_stack *stack_one, t_stack *stack_two, char *options)
{
	int		tmp;
	char	*sols;

	sols = ft_strnew(10);
	if (!stack_one->next || !stack_one->next->next)
	{
		ft_special_case(stack_one, stack_two, options);
		return ;
	}
	while (stack_one->next->next)
	{
		tmp = ft_get_min(stack_one);
		ft_move(&stack_one, ft_direction(stack_one, tmp), tmp, &sols);
		ft_p(&stack_one, &stack_two);
		sols = ft_strjoin_free(sols, "pb");
	}
	if (stack_one->number > stack_one->next->number)
		ft_s(
}
