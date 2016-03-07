/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/07 11:18:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack *test;
	
	ft_add_number(&test, 79);
	ft_add_number(&test, 28);
	ft_add_number(&test, 5);
	ft_add_number(&test, 42);
	ft_add_number(&test, 3);
	ft_add_number(&test, 12);
	
	printf("%d\n", ft_stack_med(test));

  	return(0);	
}
