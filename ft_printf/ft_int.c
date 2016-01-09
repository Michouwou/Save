/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:08:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/08 15:12:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_int(char *flaglen, char **str, int beg, intmax_t nb)
{
	wchar_t	*res;
	int		i;

	i = beg;
	while (!ft_what_type(*str[i]))
		i++;
	res = ft_itowa_(nb, *str[i])
	ft_complete_int(&res, flaglen);
	return (res);
}
