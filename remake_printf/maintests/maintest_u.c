/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:54:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/02 14:38:57 by mlevieux         ###   ########.fr       */
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

	my_printf = ft_printf("unsigned int : |%u|\n", 74893);
	real_printf = printf("unsigned int : |%u|\n", 74893);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("unsigned char : |%hhu|\n", (unsigned char)45);
	real_printf = printf("unsigned char : |%hhu|\n", (unsigned char)45);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("unsigned short : |%hu|\n", (unsigned short)15551);
	real_printf = printf("unsigned short : |%hu|\n", (unsigned short)15551);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("unsigned long : |%lu|\n", 3000000000);
	real_printf = printf("unsigned long : |%lu|\n", 3000000000);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("unsigned long long : |%llu|\n", 3000000000LL);
	real_printf = printf("unsigned long long : |%llu|\n", 3000000000LL);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("size_t : |%zu|\n", (size_t)4500);
	real_printf = printf("size_t : |%zu|\n", (size_t)4500);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("uintmax_t : |%ju|\n", (uintmax_t)5234567890);
	real_printf = printf("uintmax_t : |%ju|\n", (uintmax_t)5234567890);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (.) : |%.u|\n", 55);
	real_printf = printf("Precision (.) : |%.u|\n", 55);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (10) : |%.10u|\n", 55);
	real_printf = printf("Precision (10) : |%.10u|\n", 55);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision bonus (*) : |%.*u|\n", 4, 67);
	real_printf = printf("Precision bonus (*) : |%.*u|\n", 4, 67);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (6) : |%6u|\n", 567);
	real_printf = printf("Largeur (6) : |%6u|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) : |%*u|\n", 5, 444);
	real_printf = printf("Largeur bonus (*) : |%*u|\n", 5, 444);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (14) et precision (5) : |%14.5u|\n", 16);
	real_printf = printf("Largeur (14) et precision (5) : |%14.5u|\n", 16);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) et precision (7) : |%*.7u|\n", 9, 811);
	real_printf = printf("Largeur bonus (*) et precision (7) : |%*.7u|\n", 9, 811);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) et precision bonus (*) : |%*.*u|\n", 8, 6, 455);
	real_printf = printf("Largeur bonus (*) et precision bonus (*) : |%*.*u|\n", 8, 6, 455);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag 0 : |%05u|\n", 32);
	real_printf = printf("Flag 0 : |%05u|\n", 32);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-5u|\n", 32);
	real_printf = printf("Flag - : |%-5u|\n", 32);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag + : |%+u|\n", 567);
	real_printf = printf("Flag + : |%+u|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag ' ' : |% u|\n", 567);
	real_printf = printf("Flag ' ' : |% u|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - et largeur (12) et precision (6) : |%-12.6u|\n", 345);
	real_printf = printf("Flag - et largeur (12) et precision (6) : |%-12.6u|\n", 345);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
