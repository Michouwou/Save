/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:34:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 15:23:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	printf_loop(T_LIST **tmp, va_list *args, char **result, int *buffer)
{
	int state_value;

	state_value = 1;
	while (--((*tmp)->unused))
		va_arg(*args, void*);
	if ((*tmp)->width == -10)
		(*tmp)->width = va_arg(*args, int);
	if ((*tmp)->accuracy == -10)
		(*tmp)->accuracy = va_arg(*args, int);
	if (ft_type_crossroad(*tmp, args, result, buffer) == 0)
		state_value = 0;
	free((*tmp)->mod);
	*tmp = (*tmp)->next;
	return (state_value);
}

int			ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			state_value;
	T_LIST		**list;
	char		*result;
	int			*buffer;

	list = (T_LIST**)malloc(sizeof(T_LIST*) * 2);
	va_start(args, fmt);
	result = ft_strdup(fmt);
	state_value = 1;
	buffer = (int*)malloc(sizeof(int));
	*buffer = 0;
	list[0] = ft_get_args(ft_strdup(fmt), buffer);
	list[1] = list[0];
	while (list[1])
		state_value = printf_loop(list + 1, &args, &result, buffer);
	write(1, result, ft_strlen(result));
	state_value = (state_value) ? ft_strlen(result) + *buffer : -1;
	free(result);
	free(buffer);
	ft_free_list(list);
	free(list);
	return (state_value);
}
