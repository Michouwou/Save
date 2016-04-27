/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:01:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/27 17:49:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int		ft_call_uint(uintmax_t number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = ft_ubase(number, trail->format);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}

int		ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	printf("SAY\n");fflush(stdout);
	result = ft_base(number, trail->format);
	printf("SAY\n");fflush(stdout);
	if (trail->format == 'X')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	printf("SAY\n");fflush(stdout);
	return (state_value);
}
