/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:05:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 14:26:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(void)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->min = 2147483647;
	stack->max = -1;
	stack->len = 0;
	return (stack);
}

t_stack	*ft_fill_stack(char **args, int argc, char *options)
{
	int		i;
	int		tmp;
	t_stack	*result;

	i = 0;
	result = ft_new_stack();
	result->stack = (int*)malloc(sizeof(int) * argc);
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (ft_check_args(result->stack, i + 1, tmp, options))
			result->stack[i] = tmp;
		else
			ft_error();
		result->len++;
		i++;
	}
	return (result);
}
