/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:20:00 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/28 16:03:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	wchar_t c;

	c = 8364;
	int i = 9;
	size_t u = 864;
	char op= 'o';
	T_LIST *p = malloc(sizeof(T_LIST));
	ft_printf("Salut %#9d oh\n", i);
	printf("Salut %#9d oh\n", i);
	return (0);
}
