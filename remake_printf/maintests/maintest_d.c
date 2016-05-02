/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:54:51 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/02 14:33:21 by mlevieux         ###   ########.fr       */
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

	my_printf = ft_printf("int : |%d|\n", 74893);
	real_printf = printf("int : |%d|\n", 74893);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("char : |%hhd|\n", (char)45);
	real_printf = printf("char : |%hhd|\n", (char)45);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("short : |%hd|\n", (short)15551);
	real_printf = printf("short : |%hd|\n", (short)15551);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("long : |%ld|\n", 3000000000);
	real_printf = printf("long : |%ld|\n", 3000000000);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("long long : |%lld|\n", 3000000000LL);
	real_printf = printf("long long : |%lld|\n", 3000000000LL);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("size_t : |%zd|\n", (size_t)4500);
	real_printf = printf("size_t : |%zd|\n", (size_t)4500);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("intmax_t : |%jd|\n", (intmax_t)5234567890);
	real_printf = printf("intmax_t : |%jd|\n", (intmax_t)5234567890);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (.) : |%.d|\n", 55);
	real_printf = printf("Precision (.) : |%.d|\n", 55);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (10) : |%.10d|\n", 55);
	real_printf = printf("Precision (10) : |%.10d|\n", 55);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision bonus (*) : |%.*d|\n", 4, 67);
	real_printf = printf("Precision bonus (*) : |%.*d|\n", 4, 67);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (6) : |%6d|\n", 567);
	real_printf = printf("Largeur (6) : |%6d|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) : |%*d|\n", 5, 444);
	real_printf = printf("Largeur bonus (*) : |%*d|\n", 5, 444);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (14) et precision (5) : |%14.5d|\n", 16);
	real_printf = printf("Largeur (14) et precision (5) : |%14.5d|\n", 16);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) et precision (7) : |%*.7d|\n", 9, 811);
	real_printf = printf("Largeur bonus (*) et precision (7) : |%*.7d|\n", 9, 811);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) et precision bonus (*) : |%*.*d|\n", 8, 6, 455);
	real_printf = printf("Largeur bonus (*) et precision bonus (*) : |%*.*d|\n", 8, 6, 455);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag 0 : |%05d|\n", 32);
	real_printf = printf("Flag 0 : |%05d|\n", 32);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-5d|\n", 32);
	real_printf = printf("Flag - : |%-5d|\n", 32);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag + : |%+d|\n", 567);
	real_printf = printf("Flag + : |%+d|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag ' ' : |% d|\n", 567);
	real_printf = printf("Flag ' ' : |% d|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - et largeur (12) et precision (6) : |%-12.6d|\n", 345);
	real_printf = printf("Flag - et largeur (12) et precision (6) : |%-12.6d|\n", 345);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
