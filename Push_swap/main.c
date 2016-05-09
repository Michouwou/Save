/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:24:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 14:51:42 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*options;
	t_stack	*stack_one;
	t_stack	*stack_two;
	int		is_stat;

	is_stat = 0;
	options = ft_strnew(4);
	stack_one = ft_create_stack(av + ft_get_options(options, av, &is_stat));
	stack_two = NULL;
	if (is_stat)
		ft_loop_stat(stack_one, stack_two, options);
	else
		ft_core(stack_one, stack_two, options);
	return (0);
}
