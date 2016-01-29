/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/29 15:10:41 by mlevieux         ###   ########.fr       */
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
	ft_printf("Salut %d oh\n", i);
	printf("Salut %d oh %lld\n", i, b);
	return (0);
}
