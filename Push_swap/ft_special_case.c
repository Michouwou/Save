/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:05:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 15:41:12 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_two(t_stack *stack, char *options)
{
	char	*sols;

	sols = ft_strnew(10);
	if (stack->number > stack->next->number)
		sols = ft_strjoin_free(sols, "sa");
	ft_display(sols, options);
	free(sols);
}

void	ft_special_case(t_stack *stack, char *options)
{
	char	*sols;

	sols = ft_strnew(10);
	if (!stack->next->next)
		for_two(stack, options);
	else if (stack->number > stack->next->number &&
			stack->number > stack->next->next->number &&
			stack->next->number < stack->next->next->number)
		sols = ft_strjoin_free(sols, "ra");
	else if (stack->number > stack->next->number &&
			stack->number > stack->next->next->number &&
			stack->next->number > stack->next->next->number)
		sols = ft_strjoin_free(sols, "sa rra");
	else if (stack->number < stack->next->number &&
			stack->number > stack->next->next->number &&
			stack->next->number > stack->next->next->number)
		sols = ft_strjoin_free(sols, "rra");
	else if (stack->number > stack->next->number &&
			stack->number < stack->next->next->number &&
			stack->next->number < stack->next->next->number)
		sols = ft_strjoin_free(sols, "sa");
	else if (stack->number < stack->next->number &&
			stack->number < stack->next->next->number &&
			stack->next->number < stack->next->next->number)
		sols = ft_strjoin_free(sols, "Done");
	else if (stack->number < stack->next->number &&
			stack->number < stack->next->next->number &&
			stack->next->number > stack->next->next->number)
		sols = ft_strjoin_free(sols, "sa ra");
	ft_display(sols, options);
	free(sols);
}
