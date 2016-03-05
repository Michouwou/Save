/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 10:42:11 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack *test;
	t_stack *btest;
	t_sol	*testsol;

	test = NULL; 
	testsol = NULL;
	ft_add_sol(&testsol, "ra");
	ft_add_sol(&testsol, "pa");
	ft_add_sol(&testsol, "rra");
	ft_add_sol(&testsol, "sb");
	
	ft_add_number(&test, 7);
	ft_add_number(&test, 8);
	ft_add_number(&test, 5);
	ft_add_number(&test, 4);
	ft_add_number(&test, 3);
	ft_add_number(&test, 2);

	ft_display(testsol, ft_strnew(5));
	ft_print_stack(test);
	ft_add_sol(&testsol, ft_move(&test, &btest));
	ft_display(testsol, ft_strnew(5));
	ft_print_stack(test);
  return(0);	
}
