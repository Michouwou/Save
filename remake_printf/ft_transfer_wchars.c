/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer_wchars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:55:47 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/03 15:55:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_transfer_wchars(wchar_t *wstr, T_LIST *trail)
{
	unsigned char	*result;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	int				i;

	result = (unsigned char*)ft_strnew(0);
	i = 0;
	while (wstr[i] != 0)
	{
		tmp2 = ft_transfer_wchar(wstr[i], &(trail->oct_num));
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
