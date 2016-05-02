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

	my_printf = ft_printf("Extended character : |%C|\n", L'لا');
	real_printf = printf("Extended character : |%C|\n", L'لا');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (9) : |%9C|\n", L'हि');
	real_printf = printf("Largeur (9) : |%9C|\n", L'हि');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (8) : |%.8C|\n", L'གྲོ');
	real_printf = printf("Precision (8) : |%.8C|\n", L'གྲོ');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) : |%*C|\n", 5, L'យ');
	real_printf = printf("Largeur bonus (*) : |%*C|\n", 5, L'យ');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-3C|\n", L'h');
	real_printf = printf("Flag - : |%-3C|\n", L'h');
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
