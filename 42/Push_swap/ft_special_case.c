/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:05:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 18:10:01 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	for_two(t_stack *stack, char *options)
{
	char	*sols;

	sols = ft_strnew(10);
	if (stack->number > stack->next->number)
		sols = ft_strjoin_free(sols, "sa");
	return (ft_display(sols, options, stack));
}

static void	else_func(t_stack *stack, char **sols)
{
	if (stack->number > stack->next->number &&
			stack->number < stack->next->next->number &&
			stack->next->number < stack->next->next->number)
		*sols = ft_strjoin_free(*sols, "sa");
	else if (stack->number < stack->next->number &&
			stack->number < stack->next->next->number &&
			stack->next->number < stack->next->next->number)
		*sols = ft_strjoin_free(*sols, "");
	else if (stack->number < stack->next->number &&
			stack->number < stack->next->next->number &&
			stack->next->number > stack->next->next->number)
		*sols = ft_strjoin_free(*sols, "sa ra");
}

int			ft_special_case(t_stack *stack, char *options)
{
	char	*sols;

	if (!stack->next->next)
		return (for_two(stack, options));
	sols = ft_strnew(10);
	if (stack->number > stack->next->number &&
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
	else
		else_func(stack, &sols);
	return (ft_display(sols, options, stack));
}
