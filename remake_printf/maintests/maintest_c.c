/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:54:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/02 14:03:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
	setlocale(LC_ALL, "");

	int		my_printf;
	int		real_printf;

	printf("Usage : \n- Out ft_printf\n- Out printf\n- Return value my_printf - return value real_printf\n\n");
	fflush(stdout);

	my_printf = ft_printf("Character : |%c|\n", 'a');
	real_printf = printf("Character : |%c|\n", 'a');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Extended character : |%lc|\n", L'ሩ');
	real_printf = printf("Extended character : |%lc|\n", L'ሩ');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (9) : |%9c|\n", 't');
	real_printf = printf("Largeur (9) : |%9c|\n", 't');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (8) : |%.8c|\n", 'u');
	real_printf = printf("Precision (8) : |%.8c|\n", 'u');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) : |%*c|\n", 5, 'w');
	real_printf = printf("Largeur bonus (*) : |%*c|\n", 5, 'w');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-3c|\n", 'h');
	real_printf = printf("Flag - : |%-3c|\n", 'h');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
