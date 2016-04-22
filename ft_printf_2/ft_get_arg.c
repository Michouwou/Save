/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:15:39 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/03 12:21:10 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_arg(T_LIST *trail, char **print, va_list *args)
{
	ft_get_star(args, trail);
	if (T_ == 'd')
		ft_get_int(trail, print, args);
	if (T_ == 'p')
		ft_call_pointer(va_arg(*args, unsigned), trail, print);
	if (T_ == 'c')
		ft_call_char(va_arg(*args, wchar_t), trail, print);
	if (T_ == 'S' && trail->format == 's')
		ft_call_wstring(ft_conv_wchar(va_arg(*args, char*)), trail, print);
	else if (T_ == 'S')
		ft_call_wstring(va_arg(*args, wchar_t*), trail, print);
	if (T_ == 'f')
		ft_get_float(trail, print, args);
	if (T_ == 'E')
		ft_call_errno(trail, print);
}
