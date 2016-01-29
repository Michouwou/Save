/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:50:22 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/29 10:23:30 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_what_type(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'o'
			|| c == 'O' || c == 'x' || c == 'X')
		return (INT_TYPE);
	else if (c == 'c' || c == 'C')
		return (CHAR_TYPE);
	else if (c == 'p')
		return (POINTER_TYPE);
	else if (c == 'S' || c == 's')
		return (WSTRING_TYPE);
	else if (c == 'e' || c == 'E' || c == 'f' || c == 'F' /* || c == 'g' ||
			c == 'G'*/)
		return (DOUBLE_TYPE);
	else
		return (NOT_TYPE);
}
