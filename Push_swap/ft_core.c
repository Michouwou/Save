/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 10:32:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 11:15:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_core(t_stack *stack_one, t_stack *stack_two, char *options)
{
	int		tmp;
	t_stack	**tmps;
	char	*sols;

	if (!stack_one->next)
	{
		if (options[2])
			write(1, "\033[044;33m0 operations pour 1 entrees\033[0;m\n", 42);
		return (0);
	}
	if (!options[0])
		ft_check_doubles(stack_one);
	if (!stack_one->next || !stack_one->next->next)
		return (ft_special_case(stack_one, options));
	sols = ft_strnew(10);
	while (stack_one->next->next)
	{
		tmp = ft_get_min(stack_one);
		tmps = (t_stack**)malloc(sizeof(t_stack*) * 2);
		tmps[0] = stack_one;
		tmps[1] = stack_two;
		ft_move(&tmps, ft_direction(stack_one, tmp) +
				(options[1] ? 10 : 0), tmp, &sols);
		ft_p(&stack_two, &stack_one, options[1] ? 1 : 0);
		if (options[1])
			ft_print_stack(stack_one, stack_two, NULL);
		sols = ft_strjoin_free(sols, " pb");
	}
	if (stack_one->number > stack_one->next->number)
	{
		ft_s(&stack_one);
		if (options[1])
		{
			write(1, "\nAction : sa", 12);
			ft_print_stack(stack_one, stack_two, NULL);
		}
		sols = ft_strjoin_free(sols, " sa");
	}
	ft_repush(&stack_two, &stack_one, &sols, options[1]);
	return (ft_display(sols, options, stack_one));
}
