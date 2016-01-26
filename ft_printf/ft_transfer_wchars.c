/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfer_wchars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:06:26 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/26 11:35:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned char *ft_transfer_wchars(wchar_t *wstr)
{
	unsigned char	*result;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	int				i;

	result = ft_strnew(0);
	while (wstr[i] != 0)
	{
		tmp2 = ft_transfer_wchar(wstr[i]);
		tmp = result;
		result = ft_strnew(ft_strlen(result) + ft_strlen(tmp2));
		ft_strcat(result, tmp);
		ft_strcat(result, tmp2);
		free(tmp);
		i++;
	}
	return (result);
}
