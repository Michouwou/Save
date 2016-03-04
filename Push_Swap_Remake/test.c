/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 15:38:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack *test;
	t_stack *btest;

	test = ft_create_element('a');
	printf("test->element = %d, test->first = %d, test->next->element = %d, test->name = %s\n", test->element, test->first, test->next->element, test->name);
	btest = ft_create_element('b');
	
	ft_add_number(&test, 8);
	ft_add_number(&test, 6);
	ft_add_number(&test, 9);
	ft_add_number(&test, 11);
	ft_add_number(&test, 2);
	ft_add_number(&btest, 7);

	ft_print_stack(test);
	ft_printf("\n-<a\nb>-\n");
	ft_print_stack(btest);

	ft_pa(&test, &btest);

	ft_print_stack(test);
	ft_printf("\n-<a\nb>-\n");
	ft_print_stack(btest);

	ft_rr(&test, &btest);
	ft_print_stack(test);	
	ft_printf("\n-<a\nb>-\n");
	ft_print_stack(btest);

	ft_rrr(&test, &btest);
	ft_print_stack(test);	
	ft_printf("\n-<a\nb>-\n");
	ft_print_stack(btest);

	ft_ss(&test, &btest);
	ft_print_stack(test);	
	ft_printf("\n-<a\nb>-\n");
	ft_print_stack(btest);



  return(0);	
}
