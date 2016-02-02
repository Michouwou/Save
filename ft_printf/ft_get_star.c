/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_star.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:10:15 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/02 15:23:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_star(va_list *args, T_LIST *trail)
{
	if (trail->width == -10)
		trail->width = va_arg(*args, int);
	else if (trail->accuracy == -10)
		trail->accuracy = va_arg(*args, int);
}
