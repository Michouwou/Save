/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer_wchars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:06:26 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 17:40:46 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_transfer_wchars(wchar_t *wstr)
{
	unsigned char	*result;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	int				i;

	result = (unsigned char*)ft_strnew(0);
	while (wstr[i] != 0)
	{
		tmp2 = ft_transfer_wchar(wstr[i]);
		tmp1 = result;
		result = (unsigned char*)ft_strnew(ft_strlen((char*)result) +
				ft_strlen((char*)tmp2));
		ft_strcat((char*)result, (char*)tmp1);
		ft_strcat((char*)result, (char*)tmp2);
		free(tmp1);
		i++;
	}
	return ((char*)result);
}
