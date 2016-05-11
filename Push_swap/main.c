/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:24:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 16:08:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	usage(void)
{
	write(1, "Usage : ./push_swap [-cvdp] [--stat] n1 n2 n3 [...]\n-c Is", 57);
	write(1, " en extended-colors option that prints the different", 52);
	write(1, " actions in a color that is theirs\n-d Option enables to", 55);
	write(1, " input multiple times the same argument\n-p Is a precision", 57);
	write(1, " option that tells how many actions were necessary for the", 58);
	write(1, " number of arguments given\n-v Option outpouts the state", 55);
	write(1, " of stacks A and B after each action is applied to them\n", 56);
	exit(0);
}

int			main(int ac, char **av)
{
	char	*options;
	t_stack	*stack_one;
	t_stack	*stack_two;
	int		is_stat;

	is_stat = 0;
	options = ft_strnew(4);
	stack_one = ft_create_stack(av + ft_get_options(options, av, &is_stat), 0);
	stack_two = NULL;
	if (!stack_one && !is_stat)
		usage();
	if (is_stat)
		ft_loop_stat(stack_one, stack_two, options);
	else
	{
		ft_core(stack_one, stack_two, options);
		write(1, "\n", 1);
	}
	free(options);
	return (0);
}
