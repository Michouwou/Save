/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:25:57 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/24 15:18:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    ft_what_type(char c)
{
    if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'o'
            || c == 'O' || c == 'x' || c == 'X' || c == 'b')
        return (INT_TYPE);
    else if (c == 'c' || c == 'C')
        return (CHAR_TYPE);
    else if (c == 'p')
        return (POINTER_TYPE);
    else if (c == 'S' || c == 's')
        return (WSTRING_TYPE);
    else if (c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' ||
            c == 'G')
        return (DOUBLE_TYPE);
    else if (c == 'm')
        return (ERRNO);
	else if (c == '%')
		return (PERCENT);
	else
        return (NOT_TYPE);
}
