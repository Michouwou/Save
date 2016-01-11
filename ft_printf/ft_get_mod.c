/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:26:59 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/10 16:07:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_get_mod(char *format, int start, int end)
{
	char *mod;

	mod = (char*)malloc(sizeof(char) * 2);
	if ((end - 2) <= start && !ft_is_mod(format[end - 1]))
		mod[0] = 0;
	else if ((end - 2) <= start && ft_is_mod(format[end - 1]))
	{
		mod[0] = format[end - 1];
		mod[1] = 0;
	}
	else
	{
		if (ft_is_mod(format[end - 2]))
		{
			mod[0] = format[end - 2];
			mod[1] = format[end - 1];
		}
		else if (ft_is_mod(format[end - 1]))
		{
			mod[0] = format[end - 1];
			mod[1] = 0;
		}
		else
			mod[0] = 0;
	}
	return (mod);
}
