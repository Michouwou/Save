/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer_wchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:02:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 16:36:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned char *ft_transfer_wchar(wchar_t c)
{
	unsigned char *b_static;
	unsigned char *b;

	b_static = (unsigned char*)ft_strnew(4);
	b = b_static;
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*b++ = (unsigned char)((c >> 6) | 0xC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*b++ = (unsigned char)(((c >> 18)) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
	return (b_static);
}
