/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 10:11:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	wchar_t c;

	c = 8364;
	size_t i = 876543;
	long long b = i;
	size_t u = 864;
	char op= 'o';
	T_LIST *p = malloc(sizeof(T_LIST));
	ft_printf("Errno = \" %m \"\n");
	printf("Salut %e oh, %.2e, %s\n", 0.00903899999, 763.3, "salut");
	return (0);
}
