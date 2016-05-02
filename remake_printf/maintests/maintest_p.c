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
	int		*p;

	p = NULL;

	printf("Usage : \n- Out ft_printf\n- Out printf\n- Return value my_printf - return value real_printf\n\n");
	fflush(stdout);

	my_printf = ft_printf("Pointeur : |%p|\n", &my_printf);
	real_printf = printf("Pointeur : |%p|\n", &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Pointeur NULL : |%p|\n", p);
	real_printf = printf("Pointeur NULL : |%p|\n", p);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (.) : |%.0p|\n", &my_printf);
	real_printf = printf("Precision (.) : |%.0p|\n", &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision (16) : |%.16p|\n", &my_printf);
	real_printf = printf("Precision (16) : |%.16p|\n", &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Precision bonus (*) : |%.*p|\n", 18, &my_printf);
	real_printf = printf("Precision bonus (*) : |%.*p|\n", 18, &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (20) : |%20p|\n", &my_printf);
	real_printf = printf("Largeur (20) : |%20p|\n", &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur bonus (*) : |%*p|\n", 25, &my_printf);
	real_printf = printf("Largeur bonus (*) : |%*p|\n", 25, &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Largeur (19) et precision bonus (*) : |%19.*p|\n", 18, &my_printf);
	real_printf = printf("Largeur (19) et precision bonus (*) : |%19.*p|\n", 18,&my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag - : |%-19p|\n", &my_printf);
	real_printf = printf("Flag - : |%-19p|\n", &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);

	my_printf = ft_printf("Flag 0 : |%020p|\n", &my_printf);
	real_printf = printf("Flag 0 : |%020p|\n", &my_printf);
	printf("Difference between return value : %d\n\n", my_printf - real_printf);
	fflush(stdout);
}
