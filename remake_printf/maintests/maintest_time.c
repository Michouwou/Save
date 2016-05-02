/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:57:49 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/30 17:37:41 by mlevieux         ###   ########.fr       */
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
	ft_printf("%s, %d, %p, %c, %%, %f, %e", "Salut", 500000, &nb, 'a', 12.98, 123.987);
	end_me = clock();

	start_printf = clock();
	printf("%s, %d, %p, %c, %%, %f, %e", "Salut", 500000, &nb, 'a', 12.98, 123.987);
	end_printf = clock();

	printf("\nExecution time for ft_printf : %f sec...\nExecution time for printf : %f sec...\n", (double)(end_me - start_me), (double)(end_printf - start_printf));
	printf("%d%% moins rapide que le vrai printf\n", (int)((end_me - start_me) / (end_printf - start_printf) * 100));
	fflush(stdout);
}
