/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_apply_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:38:28 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/29 10:35:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	ft_int_apply_mod(T_LIST *trail, long long int number)
{
	char	*c;
	char	t;
	int		sign;

	c = trail->mod;
	t = trail->format;
	printf("%d\n", number);
	printf("HEY HEY HEY%s\n", c);
	sign = (t == 'd' || t == 'D' || t == 'i') ? 1 : 0;
	if (!ft_strcmp(c, "z"))
		return ((size_t)number);
	else if (!ft_strcmp(c, "h"))
		return (sign ? (short)number : (unsigned short)number);
	else if (!ft_strcmp(c, "hh"))
		return (sign ? (char)number : (unsigned char)number);
	else if (!ft_strcmp(c, "l") || t == 'D' || t == 'O' || t == 'U')
		return (sign ? (long)number : (unsigned long)number);
	else if (!ft_strcmp(c, "ll"))
		return (sign ? (long long)number : (unsigned long long)number);
	else if (!ft_strcmp(c, "j"))
		return ((intmax_t)number);
	printf("Je passe au bon endroit\n");
	return (sign ? (int)(number) : (unsigned int)(number));
}
