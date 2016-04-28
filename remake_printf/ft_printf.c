/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:34:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/28 18:11:30 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define SAY(m) printf(m);fflush(stdout);

int		ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			state_value;
	T_LIST		*args_data;
	char		*result;
	int			*buffer;

	va_start(args, fmt);
	result = ft_strdup(fmt);
	state_value = 1;
	buffer = (int*)malloc(sizeof(int));
	*buffer = 0;
	args_data = ft_get_args(ft_strdup(fmt), buffer);
	while (args_data)
	{
		while (--(args_data->unused))
			va_arg(args, void*);
		if (args_data->width == -10)
			args_data->width = va_arg(args, int);
		if (args_data->accuracy == -10)
			args_data->accuracy = va_arg(args, int);
		if (ft_type_crossroad(args_data, &args, &result, buffer) == 0)
			state_value = 0;
		args_data = args_data->next;
	}
	ft_putstr(result);
	ft_free_list(&args_data);
	return (state_value ? ft_strlen(result) + *buffer : -1);
}
