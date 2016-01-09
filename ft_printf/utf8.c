/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:21:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 12:16:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

void utf8()
{
	char *locale;
	wchar_t *try;

	locale = setlocale(LC_ALL, "");
	try = malloc(sizeof(wchar_t) * 2);
	try[0] = 196;
	try[1] = 0;
	printf("%S\n", try);
}
