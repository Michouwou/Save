/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:49:55 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/03 12:19:46 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_get_float(T_LIST *trail, char **print, va_list *args)
{
    if (trail->mod[0] != 'L' && trail->format != 'F')
        ft_call_float(va_arg(*args, double), trail, print);
    else if (trail->mod[0] == 'L' || trail->format == 'F')
        ft_call_float(va_arg(*args, double), trail, print);
}
