/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:06:18 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 14:31:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int			ft_strlen(char *str);

wchar_t		*ft_conv_wchar(char *str)
{
	wchar_t	*res;
	int		i;

	i = -1;
	res = (wchar_t*)malloc(sizeof(wchar_t) * ft_strlen(str));
	while (str[++i] != 0)
		res[i] = (unsigned char)str[i];
	res[i] = 0;
	return (res);
}
