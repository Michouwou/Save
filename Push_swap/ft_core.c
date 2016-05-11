/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 10:32:48 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 14:27:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_possibilities(t_stack *stack_one, char *options, char **sols)
{
	if (!stack_one->next)
	{
		if (options[2])
			write(1, "\033[044;33m0 operations pour 1 entrees\033[0;m\n", 42);
		return (0);
	}
	if (!options[0])
		ft_check_doubles(stack_one);
	if (!stack_one->next->next || !stack_one->next->next->next)
		return (ft_special_case(stack_one, options));
	*sols = ft_strnew(10);
	return (-1);
}

static void	last(t_stack **s_one, t_stack *s_two, char *options, char **sols)
{
	ft_s(s_one);
	if (options[1])
	{
		write(1, "\nAction : sa", 12);
		ft_print_stack(*s_one, s_two, NULL);
	}
	*sols = ft_strjoin_free(*sols, " sa");
}

int			ft_core(t_stack *stack_one, t_stack *stack_two, char *options)
{
	int		tmp[2];
	t_stack	**tmps;
	char	*sols;

	if ((tmp[0] = check_possibilities(stack_one, options, &sols)) != -1)
		return (tmp[0]);
	while (stack_one->next->next)
	{
		tmp[1] = ft_get_min(stack_one);
		tmp[0] = ft_direction(stack_one, tmp[1]) + (options[1] ? 10 : 0);
		ft_move(&stack_one, stack_two, tmp, &sols);
		ft_p(&stack_two, &stack_one, options[1] ? 1 : 0);
		if (options[1])
			ft_print_stack(stack_one, stack_two, NULL);
		sols = ft_strjoin_free(sols, " pb");
	}
	if (stack_one->number > stack_one->next->number)
		last(&stack_one, stack_two, options, &sols);
	ft_repush(&stack_two, &stack_one, &sols, options[1]);
	return (ft_display(sols, options, stack_one));
}
