/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:08:58 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/19 16:49:29 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_format(char format)
{
	if (format == 'd' || format == 'D' || format == 'i' || format == 'o' ||
			format == 'O' || format == 'x' || format == 'X' || format == 'e' ||
			format == 'E' || format == 'f' || format == 'F' || format == 'p' ||
			format == 'n' || format == 'm' || format == 'b')
		return (1);
}
