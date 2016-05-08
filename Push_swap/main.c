/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:24:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 14:02:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*options;
	t_stack	*stack_one;
	t_stack	*stack_two;

	options = ft_strnew(5);
	stack_one = ft_create_stack(av + ft_get_options(options, av));
	stack_two = NULL;
	ft_core(stack_one, stack_two, options);
	return (0);
}
