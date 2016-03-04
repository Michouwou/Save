/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/04 14:10:57 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack *test;

	test = ft_create_element('a');
	printf("test->element = %d, test->first = %d, test->next->element = %d, test->name = %s\n", test->element, test->first, test->next->element, test->name);

	
	ft_add_number(&test, 8);
	ft_add_number(&test, 6);
	ft_add_number(&test, 9);
	ft_add_number(&test, 11);
	ft_add_number(&test, 2);
	ft_print_stack(test);

	ft_ra(test);
	ft_print_stack(test);

  return(0);	
}
