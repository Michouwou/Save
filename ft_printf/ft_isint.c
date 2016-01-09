/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 13:22:14 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/09 16:25:22 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define CORRECT_FLAG 1
#define NO_SPEC_FLAG 0

int		ft_what_type(char f)
{
	if (f == 'D' || f == 'U' || f == 'u' || f == 'd' || f == 'i' || f == 'O' ||
			f == 'o' || f == 'x' || f == 'X')
		return (INT_TYPE);
	if (f == 'p')
		return (POINTER_TYPE);
	if (f == 's' || f == 'S' || f == 'c' || f == 'C')
		return (CHAR_TYPE);
	else
		return (NO_SPEC_TYPE);
}

int		ft_is_flag(char f)
{
	if (f == 'j' || f == 'z' || f == '#' || f == 48 || f == '-' || f == '+' ||
			f == ' ')
		return (CORRECT_FLAG);
	else
		return (NO_SPEC_FLAG);
}
