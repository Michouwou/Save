/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:57:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/05 13:09:50 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <time.h>
#include <limits.h>
#include "libftprintf.h"

int main()
{
	int		nb;
	clock_t	start_me;
	clock_t end_me;
	clock_t time_me;
	clock_t start_printf;
	clock_t end_printf;
	clock_t	time_printf;

	start_me = clock();
	ft_printf("%d, %s, %p, %c\n", 53, "Yo", &nb, 'a');
	end_me = clock();

	start_printf = clock();
	printf("%d, %s, %p, %c\n", 53, "Yo", &nb, 'a');
	end_printf = clock();

	printf("\nExecution time for ft_printf : %f \nExecution time for printf : %f \n", (double)(end_me - start_me) / 1000, (double)(end_printf - start_printf) / 1000);
	printf("%d%% moins rapide que le vrai printf\n", (int)((end_me - start_me) / (end_printf - start_printf) * 100));
	fflush(stdout);
}
