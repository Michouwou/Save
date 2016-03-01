/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:05:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 16:19:03 by mlevieux         ###   ########.fr       */
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
	stack->name = ft_strnew(1);
	return (stack);
}

t_stack	*ft_fill_stack(char **args, int argc, char *options)
{
	printf("\tOn est dans fill_stack\n\n");
	fflush(stdout);

	int		i;
	int		tmp;
	t_stack	*result;

	i = 1;
	result = ft_new_stack();

	printf("\tCreation de la stack OK\n\n");
	fflush(stdout);

	result->stack = (int*)malloc(sizeof(int) * argc);

	printf("\tAllocation de la stack OK\n\n");
	fflush(stdout);

	while (i < argc)
	{
		tmp = ft_atoi(args[i]);

		printf("\t\tNumerisation de args[i] (= %s) argument! tmp = %d\n", args[i], tmp);
		fflush(stdout);

		if (ft_check_args(result->stack, i, (long)tmp, options))
			result->stack[i - 1] = tmp;
		else
			ft_error(0);
	
		printf("\t\tArgument actuel OK\n");
		fflush(stdout);

		result->len++;
		i++;
	}

	printf("Arrivons a la valeur de retour!\n");
	fflush(stdout);
	return (result);
}
