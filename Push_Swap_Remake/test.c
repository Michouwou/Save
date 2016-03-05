/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack *test;
	t_stack *btest;
	t_sol	*testsol;

	test = NULL;
	btest = NULL;
	testsol = NULL;
	ft_add_sol(&testsol, "ra");
	ft_add_sol(&testsol, "pa");
	ft_add_sol(&testsol, "rra");
	ft_add_sol(&testsol, "sb");
	
	ft_add_number(&test, 79);
	ft_add_number(&test, 28);
	ft_add_number(&test, 5);
	ft_add_number(&test, 42);
	ft_add_number(&test, 3);
	ft_add_number(&test, 12);
	ft_add_number(&btest, 8);
	ft_add_number(&btest, 31);
	ft_add_number(&btest, 4);
	ft_add_number(&btest, 41);
	ft_add_number(&btest, 300);
	ft_add_number(&btest, 14);
	

	ft_print_stack(test);
	ft_print_stack(btest);
	ft_restack(test, btest);
	ft_print_stack(test);
	ft_print_stack(btest);
  return(0);	
}
