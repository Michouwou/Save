/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_uuu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:30:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 16:38:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned char *ft_transfer_wchar(wchar_t wc);

int main()
{
	wchar_t c = 8364;
	char *str;

	str = (char*)ft_transfer_wchar(c);
	int i = 0;
	while (str[i] != 0)
		write(1, &str[i++], 1);
	return 0;
}
