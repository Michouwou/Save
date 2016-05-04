/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:34:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/04 11:46:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
* Faudra revenir sur celle la pour la norme!
**/

int		ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			state_value;
	T_LIST		*args_data;
	T_LIST		*tmp;
	char		*result;
	int			*buffer;

	va_start(args, fmt);
	result = ft_strdup(fmt);
	state_value = 1;
	buffer = (int*)malloc(sizeof(int));
	*buffer = 0;
	args_data = ft_get_args(ft_strdup(fmt), buffer);
	tmp = args_data;
	while (tmp)
	{
		while (--(tmp->unused))
			va_arg(args, void*);
		if (args_data->width == -10)
			tmp->width = va_arg(args, int);
		if (args_data->accuracy == -10)
			tmp->accuracy = va_arg(args, int);
		if (ft_type_crossroad(tmp, &args, &result, buffer) == 0)
			state_value = 0;
		free(tmp->mod);
		tmp = tmp->next;
	}
	//ft_putstr(result);
	write(1, result, ft_strlen(result));
	*buffer = ft_strlen(result) + *buffer;
	free(result);
	ft_free_list(&args_data);
	return (state_value ? *buffer : -1);
}
