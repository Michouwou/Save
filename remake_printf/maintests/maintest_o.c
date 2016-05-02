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

	my_printf = ft_printf("octal : |%o|\n", 74893);
	real_printf = printf("octal : |%o|\n", 74893);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("(char) octal : |%hho|\n", (char)45);
	real_printf = printf("(char) octal : |%hho|\n", (char)45);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("(short) octal : |%ho|\n", (short)15551);
	real_printf = printf("(short) octal : |%ho|\n", (short)15551);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("(long) octal : |%lo|\n", 3000000000);
	real_printf = printf("(long) octal : |%lo|\n", 3000000000);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("(long long) octal : |%llo|\n", 3000000000LL);
	real_printf = printf("(long long) octal : |%llo|\n", 3000000000LL);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("(size_t) octal : |%zo|\n", (size_t)4500);
	real_printf = printf("(size_t) octal : |%zo|\n", (size_t)4500);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("(intmax_t) octal : |%jo|\n", (intmax_t)5234567890);
	real_printf = printf("(intmax_t) octal : |%jo|\n", (intmax_t)5234567890);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (.) : |%.o|\n", 55);
	real_printf = printf("Precision (.) : |%.o|\n", 55);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (10) : |%.10o|\n", 55);
	real_printf = printf("Precision (10) : |%.10o|\n", 55);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision bonus (*) : |%.*o|\n", 4, 67);
	real_printf = printf("Precision bonus (*) : |%.*o|\n", 4, 67);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (6) : |%6o|\n", 567);
	real_printf = printf("Largeur (6) : |%6o|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) : |%*o|\n", 5, 444);
	real_printf = printf("Largeur bonus (*) : |%*o|\n", 5, 444);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (14) et precision (5) : |%14.5o|\n", 16);
	real_printf = printf("Largeur (14) et precision (5) : |%14.5o|\n", 16);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) et precision (7) : |%*.7o|\n", 9, 811);
	real_printf = printf("Largeur bonus (*) et precision (7) : |%*.7o|\n", 9, 811);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) et precision bonus (*) : |%*.*o|\n", 8, 6, 455);
	real_printf = printf("Largeur bonus (*) et precision bonus (*) : |%*.*o|\n", 8, 6, 455);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag 0 : |%05o|\n", 32);
	real_printf = printf("Flag 0 : |%05o|\n", 32);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-5o|\n", 32);
	real_printf = printf("Flag - : |%-5o|\n", 32);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag + : |%+o|\n", 567);
	real_printf = printf("Flag + : |%+o|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag ' ' : |% o|\n", 567);
	real_printf = printf("Flag ' ' : |% o|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag # : |%#o|\n", 567);
	real_printf = printf("Flag # : |%#o|\n", 567);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - et largeur (12) et precision (6) : |%-12.6o|\n", 345);
	real_printf = printf("Flag - et largeur (12) et precision (6) : |%-12.6o|\n", 345);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
