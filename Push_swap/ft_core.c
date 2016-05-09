/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 10:32:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 18:31:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_core(t_stack *stack_one, t_stack *stack_two, char *options)
{
	int		tmp;
	char	*sols;

	if (!options[0])
		ft_check_doubles(stack_one);
	sols = ft_strnew(10);
	if (!stack_one->next || !stack_one->next->next)
		return(ft_special_case(stack_one, options));
	while (stack_one->next->next)
	{
		tmp = ft_get_min(stack_one);
		ft_move(&stack_one, ft_direction(stack_one, tmp) + (options[1] ? 10 : 0), tmp, &sols);
		ft_p(&stack_two, &stack_one);
		if (options[1])
			ft_print_stack(stack_one, stack_two, NULL);
		sols = ft_strjoin_free(sols, " pb");
	}
	if (stack_one->number > stack_one->next->number)
	{
		ft_s(&stack_one);
		if (options[1])
			ft_print_stack(stack_one, stack_two, NULL);
		sols = ft_strjoin_free(sols, " sa");
	}
	ft_repush(&stack_two, &stack_one, &sols, options[1]);
	return (ft_display(sols, options, stack_one));
}
