/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:34:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/23 02:13:43 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_set_width(char *result, T_LIST *trail, int *state_value)
{
	int i;

	i = 0;
	while (!ft_isdigit(result[i]) && result[i] != '+' && result[i] != '-' &&
			result[i] != 0 && (trail->type == 'd' || trail->type == 'f'))
		i++;
	if (trail->width > (int)ft_strlen(result))
	{
		if (!(trail->minus))
		{
			if (trail->z_pad && !(trail->accuracy != -1 && trail->type == 'd'))
				result = ft_repstr(result, (result[i] == '+' || result[i] == '-'
							) ? i = i + 1 : i, i,
						ft_strset(ft_strnew(trail->width - ft_strlen(result)),
							trail->width - ft_strlen(result), '0'));
			else
				result = ft_repstr(result, i, i,
						ft_strset(ft_strnew(trail->width - ft_strlen(result)),
							trail->width - ft_strlen(result), ' '));
		}
		else
			result = ft_repstr(result, ft_strlen(result), ft_strlen(result),
					ft_strset(ft_strnew(trail->width - ft_strlen(result)),
						trail->width - ft_strlen(result), ' '));
	}
	return (result);
}

char    *ft_set_length(T_LIST *trail, char *result, int *state_value)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (result[++j] != 0)
		if (ft_isdigit(result[j]))
			i++;
	i = trail->accuracy - i;
	j = 0;
	while (!ft_isdigit(result[j]) && result[j] != 0)
		j++;
	if (trail->type == 'd' && i > 0)
		result = ft_repstr(result, j, j, ft_strset(ft_strnew(i), i, '0'));
	else if (trail->type == 'S' || trail->type == 's')
		result[trail->accuracy] = 0;
	return (result);
}

char *ft_apply_flag(char *result, T_LIST *trail, int *state_value)
{
	char t;

	t = trail->format;
	if ((trail->type == 'd' || trail->type == 'f') && (trail->plus ||
				trail->space || result[0] == '-'))
	{
		if (trail->plus && ft_isdigit(result[0]) && (t != 'o' && t != 'O' &&
					t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, 0, "+");
		else if (trail->space && ft_isdigit(result[0]) && (t != 'o' && t != 'O' &&
					t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, 0, " ");
	}
	if (trail->alternate)
		result = ft_alternate(result, trail, state_value);
	return (result);
}

int		ft_int_type(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->format == 'D')
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (args_data->format == 'O' || args_data->format == 'U')
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "ll") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "ll") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned char), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, char), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned short), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, short), args_data, result));
	else if (!ft_strcmp(args_data->mod, "j") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, uintmax_t), args_data, result));
	else if (!ft_strcmp(args_data->mod, "j") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, intmax_t), args_data, result));
	else if (!ft_strcmp(args_data->mod, "z") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, size_t), args_data, result));
	else if (!args_data->mod && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned), args_data, result));
	else
		return (ft_call_int(va_arg(*args, int), args_data, result));
}

int		ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = ft_base(number, trail->format, &state_value);
	if (trail->format == 'X')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
	return (state_value);
}

int		ft_char_type(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->format == 'C' || (args_data->format == 'c' &&
				!ft_strcmp(args_data->mod, "l")))
		return (ft_call_char(va_arg(*args, wchar_t), args_data, result));
	else
		return (ft_call_char(va_arg(*args, char), args_data, result));
}

int		ft_call_char(wchar_t wc, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = (char*)ft_transfer_wchar(wc);
	result = ft_set_width(result, trail, &state_value);
	if (trail->flag)
		state_value = 0;
	result = ft_repstr(result, 0, 0, ft_strset(ft_strnew(trail->width - 1),
				trail->width - 1, ' '));
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
	return (state_value);
}

int		ft_double_type(T_LIST *args_data, va_list *args, char **result)
{
	if (!ft_strcmp(args_data->mod, "L"))
		return (ft_call_float(va_arg(*args, long double), args_data, result));
	else
		return (ft_call_float(va_arg(args, double), args_data, result));
}

int    ft_call_float(long double number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = ft_conv_float(number, (trail->accuracy != -1) ?
			trail->accuracy : 6);
	if (trail->accuracy == -2)
		state_value = 0;
	if (trail->format == 'e' || trail->format == 'E')
		result = ft_conv_exp(number, trail);
	if (trail->format == 'E')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
			result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
	return (state_value);
}

int		ft_call_pointer(unsigned address, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	state_value = 1;
	result = ft_base(address, 16, &state_value);
	result = ft_repstr(result, 0, 0, "0x");
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1, result);
	ft_move_index(&trail, trail->start_index - trail->end_index + ft_strlen(result) - 1);
	return (state_value);
}

int		ft_type_crossroad(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->type == INT_TYPE)
		return (ft_int_type(args_data, args, result));
	else if (args_data->type == CHAR_TYPE)
		return (ft_char_type(args_data, args, result));
	else if (args_data->type == POINTER_TYPE)
		return (ft_call_pointer(args_data, args, result));
	else if (args_data->type == STRING_TYPE)
		return (ft_call_string(args_data, args, result));
	else if (args_data->type == WSTRING_TYPE)
		return (ft_call_wstring(args_data, args, result));
	else if (args_data->type == DOUBLE_TYPE)
		return (ft_double_type(args_data, args, result));
	else if (args_data->type == ERRNO)
		return (ft_call_errno(args_data, args, result));
	else if (args_data->type == PERCENT)
		return (ft_call_percent(args_data, args, result));
	else
		return (ft_call_wildcard(args_data, args, result));
}

int		ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			state_value;
	T_LIST		*args_data;
	char		result;

	va_start(args, fmt);
	result = ft_strdup(fmt);
	state_value = ft_check_fmt(fmt);
	args_data = ft_get_args(fmt);
	while (args_data)
	{
		if (args_data->width == -10)
			args_data->width = va_arg(args, int);
		if (args_data->accuracy == -10)
			args_data->accuracy = va_arg(args, int);
		state_value = state_value & ft_type_crossroad(args_data, &args, &result);
		args_data = args_data->next;
	}
	ft_putstr(result);
	ft_free_data_args(data_args);	
	return (state_value ? ft_strlen(result) : -1);
}
