/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_unit_failed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:55:40 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/30 16:13:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "libftprintf.h"

int main()
{
	int my_printf;
	int real_printf;

	setlocale(LC_ALL, "");

	printf("Usage :\n- ft_printf return\n- printf return\n- Difference de retour = printf return value - ft_printf return value\n\n");

	my_printf = ft_printf("{% c}", 0);
	printf("\n");
	real_printf = printf("{% c}", 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("{% C}", 0);
	printf("\n");
	real_printf = printf("{% C}", 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("{%05.c}", 0);
	printf("\n");
	real_printf = printf("{%05.c}", 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("%hhC, %hhC", 0, L'米');
	printf("\n");
	real_printf = printf("%hhC, %hhC", 0, L'米');
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("{%*c}", 0, 0);
	printf("\n");
	real_printf = printf("{%*c}", 0, 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("{%*c}", -15, 0);
	printf("\n");
	real_printf = printf("{%*c}", -15, 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("{%03c}", 0);
	printf("\n");
	real_printf = printf("{%03c}", 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);

	my_printf = ft_printf("{%3c}", 0);
	printf("\n");
	real_printf = printf("{%3c}", 0);
	printf("\n");
	printf("Difference de retour : %d\n\n", real_printf - my_printf);
}
