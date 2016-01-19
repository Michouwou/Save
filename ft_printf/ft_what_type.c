/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:50:22 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/18 18:27:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_what_type(char c)
{
	if (c == 'd' || c == 'D' || c == 'U' || c == 'u' || c == 'o' || c == 'O' ||
			c == 'x' || c == 'X' || c == 'i')
		return (INT_TYPE);
	else if (c == 'c' || c == 'C')
		return (CHAR_TYPE);
	else if (c == 'p')
		return (POINTER_TYPE);
	else if (c == 'S')
		return (WSTRING_TYPE);
	else if (c == 'e' || c == 'E' || c == 'f' || c == 'F' /* || c == 'g' ||
			c == 'G'*/)
		return (DOUBLE_TYPE);
//	else if (c == '*')
//		return (NOT_YET_DEFINED);
	else
		return (NOT_TYPE);
}
