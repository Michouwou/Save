/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:34:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/25 16:54:46 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define SAY(m) printf(m);fflush(stdout);

static void     ft_isneg(intmax_t *num, int *k, char *final)
{
	if (*num < 0)
	{
		*num = -(*num);
		*k = 1;
		final[0] = '-';
	}
}

static void     ft_make_base(int *base)
{
	if (*base == 'o' || *base == 'O')
		*base = 8;
	if(*base == 'x' || *base == 'X')
		*base = 16;
	if (*base == 'b')
		*base = 2;
	if (*base == 'd' || *base == 'D' || *base == 'i')
		*base = 10;
}

char            *ft_base(intmax_t num, int base)
{
	char            *final;
	int             k;
	intmax_t        i;
	char            alpha[17];

	ft_make_base(&base);
	i = 1;
	k = 0;
	ft_strcpy(alpha, "0123456789abcdef");
	ft_bzero(final = (char*)malloc(sizeof(char) * 200), 200);
	ft_isneg(&num, &k, final);
	while ((i * base) <= num)
		i = i * base;
	while (i > 0)
	{
		final[k++] = alpha[(num / i)];
		num = num % i;
		i /= base;
	}
	final[k] = 0;
	return (final);
}

char    *ft_repstr(char *str, int start, int end, char *to_insert)
{
	char    *res;
	int     i;
	int     j;

	res = (char*)malloc(sizeof(char) * (ft_strlen(str) - (end - start) + ft_strlen(to_insert) + 1));
	ft_bzero(res, ft_strlen(str) - (end - start) + ft_strlen(to_insert));
	i = 0;
	j = 0;
	while (i < start)
	{
		res[i] = str[i];
		i++;
	}
	while (j < (int)ft_strlen(to_insert))
		res[i++] = (int)to_insert[j++];
	j = end;
	while (str[j] != 0)
		res[i++] = (int)str[j++];
	res[i] = 0;
	return (res);
}

char    *ft_strset(char *str, int len, char c)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

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

char    *ft_alternate(char *result, T_LIST *trail)
{
	int i;

	i = 0;
	if (trail->format == 'o' || trail->format == 'O' || trail->format == 'x' ||
			trail->format == 'X' || trail->format == 'b')
	{
		while (!ft_isalnum(result[i]))
			i++;
		if (trail->format == 'o' || trail->format == 'O')
			result = ft_repstr(result, i, i, "0");
		else if (trail->format == 'x')
			result = ft_repstr(result, i, i, "0x");
		else if (trail->format == 'X')
			result = ft_repstr(result, i, i, "0X");
		else
			result = ft_repstr(result, i, i, "b");
	}
	else if (trail->type == 'f')
	{
		while (!ft_isdigit(result[i]))
			i++;
		while (ft_isdigit(result[i]))
			i++;
		if (result[i] != '.')
			result = ft_repstr(result, i, i, ".");
	}
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
		else if (trail->space && ft_isdigit(result[0]) && (t != 'o'
				&& t != 'O' && t != 'x' && t != 'X' && t != 'b'))
			result = ft_repstr(result, 0, 0, " ");
	}
	if (trail->alternate)
		result = ft_alternate(result, trail);
	return (result);
}

int		ft_int_type(T_LIST *args_data, va_list *args, char **result)
{
	int		m;

	m = (args_data) ? 1 : 0;
	if (args_data->format == 'D')
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (args_data->format == 'O' || args_data->format == 'U')
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "ll") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long long), args_data,
			result));
	else if (!ft_strcmp(args_data->mod, "ll") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && !args_data->is_signed)
		return (ft_call_int(va_arg(*args, unsigned long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "l") && args_data->is_signed)
		return (ft_call_int(va_arg(*args, long), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && !args_data->is_signed)
		return (ft_call_int((unsigned char)va_arg(*args, unsigned), args_data, result));
	else if (!ft_strcmp(args_data->mod, "hh") && args_data->is_signed)
		return (ft_call_int((char)va_arg(*args, int), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && !args_data->is_signed)
		return (ft_call_int((unsigned short)va_arg(*args, unsigned), args_data, result));
	else if (!ft_strcmp(args_data->mod, "h") && args_data->is_signed)
		return (ft_call_int((short)va_arg(*args, int), args_data, result));
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

static void	ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int		ft_call_int(intmax_t number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	result = ft_base(number, trail->format);
	if (trail->format == 'X')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}

int		ft_char_type(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->format == 'C' || (args_data->format == 'c' &&
				!ft_strcmp(args_data->mod, "l")))
		return (ft_call_char((wchar_t)va_arg(*args, wchar_t), args_data, result));
	else
		return (ft_call_char((char)va_arg(*args, wchar_t), args_data, result));
}

int		ft_call_char(wchar_t wc, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	result = (char*)ft_transfer_wchar(wc);
	result = ft_set_width(result, trail, &state_value);
	result = ft_repstr(result, 0, 0, ft_strset(ft_strnew(trail->width - 1),
				trail->width - 1, ' '));
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}

int		ft_double_type(T_LIST *args_data, va_list *args, char **result)
{
	if (!ft_strcmp(args_data->mod, "L"))
		return (ft_call_float(va_arg(*args, long double), args_data, result));
	else
		return (ft_call_float(va_arg(*args, double), args_data, result));
}

static double   ft_power(double num, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (num * ft_power(num, pow - 1));
}

void            ft_round(long double *num, int accuracy)
{
	if ((int)(*num * ft_power(10.0, accuracy + 1)) % 10 >= 5)
		*num = *num + 1.0 / ft_power(10.0, accuracy);
}

static void     ft_is_neg(int *k, long double *number, char **final)
{
	if (*number < 0)
	{
		*number = *number * -1;
		*k = *k + 1;
		(*final)[0] = '-';
	}
}

char            *ft_conv_float(long double to_print, int accuracy)
{
	char        *final;
	int         k;
	long double i;

	i = 1.0;
	k = 0;
	final = ft_strnew(310);
	ft_is_neg(&k, &to_print, &final);
	ft_round(&to_print, accuracy);
	while (i < to_print)
		i *= 10;
	while ((i = i / 10) >= 1)
	{
		final[k++] = (int)(to_print / i) + 48;
		to_print = (long double)((intmax_t)to_print % (intmax_t)i) + to_print -
			(intmax_t)to_print;
	}
	if (k == 0)
		final[k++] = '0';
	final[k++] = (accuracy > 0) ? '.' : 0;
	while (accuracy-- > 0)
	{
		to_print *= 10;
		final[k++] = (intmax_t)to_print + 48;
		to_print = to_print - (intmax_t)to_print;
	}
	return (final);
}

char    *ft_conv_exp(long double number, T_LIST *trail)
{
	int     i;
	char    *res;

	i = 0;
	while (number >= 10.0 || number <= -10.0 )
	{
		number /= 10.0;
		i++;
	}
	while (number < 1.0 && number > -1.0)
	{
		number *= 10.0;
		i--;
	}
	res = ft_itoa(i);
	if (i < 10 && i > -10)
		res = ft_repstr(res, i < 0 ? 1 : 0, i < 0 ? 1 : 0, "0");
	if (i >= 0)
		res = ft_repstr(res, 0, 0, "+");
	res = ft_repstr(res, 0, 0, "e");
	res = ft_repstr(res, 0, 0, ft_conv_float(number, trail->accuracy > 0 ?
				trail->accuracy : 6));
	return(res);
}

int    ft_call_float(long double number, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	if (trail->format == 'f' || trail->format == 'F')
		result = ft_conv_float(number, (trail->accuracy != -1) ?
				trail->accuracy : 6);
	if (trail->format == 'e' || trail->format == 'E')
		result = ft_conv_exp(number, trail);
	if (trail->format == 'E')
		ft_strtoupper(result);
	result = ft_apply_flag(result, trail, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
			result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}

int		ft_call_pointer(unsigned pointer, T_LIST *trail, char **print)
{
	char    *result;
	int		state_value;

	result = pointer ? ft_base(pointer, 16) : ft_strdup("0");
	result = ft_repstr(result, 0, 0, "0x");
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}

wchar_t     *ft_conv_wchar(char *str)
{
	wchar_t *res;
	int     i;

	i = -1;
	if (!str)
		return (NULL);
	res = (wchar_t*)malloc(sizeof(wchar_t) * ft_strlen(str) + 1);
	while (str[++i] != 0)
		res[i] = (unsigned char)str[i];
	res[i] = 0;
	return (res);
}

unsigned char *ft_transfer_wchar(wchar_t c)
{
	unsigned char *b_static;
	unsigned char *b;

	b_static = (unsigned char*)ft_strnew(4);
	b = b_static;
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*b++ = (unsigned char)((c >> 6) | 0xC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*b++ = (unsigned char)(((c >> 18)) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
	return (b_static);
}

char *ft_transfer_wchars(wchar_t *wstr)
{
	unsigned char   *result;
	unsigned char   *tmp1;
	unsigned char   *tmp2;
	int             i;

	result = (unsigned char*)ft_strnew(0);
	i = 0;
	while (wstr[i] != 0)
	{
		tmp2 = ft_transfer_wchar(wstr[i]);
		tmp1 = result;
		result = (unsigned char*)ft_strnew(ft_strlen((char*)result) +
				ft_strlen((char*)tmp2));
		ft_strcat((char*)result, (char*)tmp1);
		ft_strcat((char*)result, (char*)tmp2);
		free(tmp1);
		i++;
	}
	return ((char*)result);
}

int    ft_call_wstring(wchar_t *wstring, T_LIST *trail, char **print)
{
	char 	*result;
	int		state_value;

	result = (wstring) ? ft_transfer_wchars(wstring) : ft_strdup("(null)");
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result) - 1);
	return (state_value);
}

void    ft_move_index(T_LIST **trail, int padding)
{
	T_LIST *tmp;

	tmp = *trail;
	while (tmp != NULL)
	{
		tmp->start_index += padding;
		tmp->end_index += padding;
		tmp = tmp->next;
	}
}

int    ft_call_errno(T_LIST *trail, char **print)
{
	char	*result;
	int		state_value;

	result = strerror(errno);
	result = ft_set_length(trail, result, &state_value);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
			result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
			ft_strlen(result) - 1);
	return (state_value);
}

int		ft_call_percent(T_LIST *trail, char **print)
{
	char	*result;
	int		state_value;

	result = ft_strdup("%");
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result));
	return (state_value);
}

int		ft_call_wildcard(T_LIST *trail, char **print)
{
	char	*result;
	int		state_value;

	result = ft_strdup(trail->wildcard);
	result = ft_set_width(result, trail, &state_value);
	*print = ft_repstr(*print, trail->start_index, trail->end_index + 1,
		result);
	ft_move_index(&trail, trail->start_index - trail->end_index +
		ft_strlen(result));
	return (state_value);
}

int		ft_type_crossroad(T_LIST *args_data, va_list *args, char **result)
{
	if (args_data->type == INT_TYPE)
		return (ft_int_type(args_data, args, result));
	else if (args_data->type == CHAR_TYPE)
		return (ft_char_type(args_data, args, result));
	else if (args_data->type == POINTER_TYPE)
		return (ft_call_pointer(va_arg(*args, unsigned), args_data, result));
	else if (args_data->type == STRING_TYPE)
		return (ft_call_wstring(ft_conv_wchar(va_arg(*args, char*)), args_data,
			result));
	else if (args_data->type == WSTRING_TYPE)
		return (ft_call_wstring(va_arg(*args, wchar_t*), args_data, result));
	else if (args_data->type == DOUBLE_TYPE)
		return (ft_double_type(args_data, args, result));
	else if (args_data->type == ERRNO)
		return (ft_call_errno(args_data, result));
	else if (args_data->type == PERCENT)
		return (ft_call_percent(args_data, result));
	else
		return (ft_call_wildcard(args_data, result));
}

void    ft_free_list(T_LIST **start)
{
	if ((*start) != NULL && (*start)->next != NULL)
		ft_free_list(&(*start)->next);
	free(*start);
}

int     ft_is_format(char format)
{
	if (format == 'd' || format == 'D' || format == 'i' || format == 'o' ||
			format == 'O' || format == 'x' || format == 'X' || format == 'e' ||
			format == 'E' || format == 'f' || format == 'F' || format == 'p' ||
			format == 'm' || format == 'b' || format == 'c' || format == 'C' ||
			format == 's' || format == 'S' || format == '%')
		return (1);
	return (0);
}

int		ft_is_valid(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ' || c == '*' ||
			c == '.' || c == 'd' || c == 'L' || c == 'l' || c == 'j' ||
			c == 'z' || c == 'h' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'D' || c == 'U' || c == 'O' || c == 'f' || c == 'm' ||
			c == 'E' || c == 'e' || c == 'X' || c == 'x' || c == 'F' ||
			c == '%' || c == 'S' || c == 's' || c == 'c' || c == 'C' ||
			c == 'p' || c == 'b' || ft_isdigit(c))
		return (1);
	return (0);
}

int		ft_check_fmt(char const *fmt)
{
	int		i;

	i = 0;
	while (ft_is_valid(fmt[i]) && !ft_is_format(fmt[i]) && fmt[i])
		++i;
	if (!ft_is_valid(fmt[i]))
		return (1); // Code incomplet
	else if (ft_is_format(fmt[i]) || !fmt[i])
		return (2); // Code ca a l'air bon
	else
		return (0); //Code y a un serieux probleme quelque part!
}

T_LIST	*ft_make_node(void)
{
	T_LIST	*new;

	new = (T_LIST*)malloc(sizeof(T_LIST));
	new->minus = 0;
	new->plus = 0;
	new->z_pad = 0;
	new->alternate = 0;
	new->space = 0;
	new->width = -1;
	new->accuracy = -1;
	new->is_signed = 0;
	new->type = 0;
	new->format = 0;
	new->mod = ft_strdup("-");
	new->incomplete = 0;
	new->next = NULL;
	return (new);
}

int		ft_is_modifier(char *str)
{
	if ((str[0] == 'l' && str[1] == 'l') || (str[0] == 'l' && str[1] != 'l') ||
		(str[0] == 'j') || (str[0] == 'z') ||
		(str[0] == 'h' && str[1] != 'h') || (str[0] == 'h' && str[1] == 'h'))
		return (1);
	return (0);
}

void	ft_get_greatest_modifier(char *fmt, int *counter, T_LIST *trail)
{
	if (fmt[*counter] == 'j')
		trail->mod = ft_strdup("j");
	else if (fmt[*counter] == 'z')
		trail->mod = ft_strdup("z");
	else if (fmt[*counter] == 'l' && fmt[*counter + 1] == 'l')
		trail->mod = ft_strdup("ll");
	else if (fmt[*counter] == 'l' && fmt[*counter + 1] != 'l' &&
		ft_strcmp(trail->mod, "ll"))
		trail->mod = ft_strdup("l");
	else if (fmt[*counter] == 'h' && fmt[*counter + 1] != 'h' &&
		trail->mod[0] != 'l')
		trail->mod = ft_strdup("h");
	else if (fmt[*counter] == 'h' && fmt[*counter + 1] == 'h' && !trail->mod)
		trail->mod = ft_strdup("hh");
}

void	ft_get_width(char *location, int *counter, T_LIST *trail)
{
	int	i;

	i = *counter;
	while (location[*counter] && ft_isdigit(location[*counter]))
		(*counter)++;
	trail->width = ft_atoi(ft_strsub(location, i, *counter - i));
	(*counter) -= 1;
}

void	ft_get_accuracy(char *location, int *counter, T_LIST *trail)
{
	int	i;
	
	i = *counter + 1;
	while (location[*counter] && ft_isdigit(location[*counter]))
		(*counter)++;
	trail->accuracy = ft_atoi(ft_strsub(location, i, *counter - i));
	(*counter) -= 1;
}

void	ft_get_fmt(T_LIST *trail, char fmt)
{
	if (fmt == 'd' || fmt == 'i' || fmt == 'o' || fmt == 'u' || fmt == 'D' ||
		fmt == 'O' || fmt == 'x' || fmt == 'X' || fmt == 'U' || fmt == 'b')
		trail->type = 'd';
	else if (fmt == 'e' || fmt == 'E' || fmt == 'f' || fmt == 'F')
		trail->type = 'f';
	else if (fmt == 'c' || fmt == 'C')
		trail->type = 'c';
	else
		trail->type = fmt;
	trail->format = fmt;
}

void	ft_wildcard(T_LIST *trail, char *fmt, int *i)
{
	trail->wildcard = ft_strset(ft_strnew(1), 1, fmt[*i]);
}

T_LIST	*ft_get_args(char *fmt)
{
	T_LIST	*args;
	T_LIST	*tmp;
	int		i;
	int		j;

	args = ft_make_node();
	tmp = args;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			tmp->next = ft_make_node();
			tmp = tmp->next;
			tmp->start_index = i++;
			while (ft_is_valid(fmt[i]) && !ft_is_format(fmt[i]))
			{
				if (fmt[i] == '-')
					tmp->minus = 1;
				else if (fmt[i] == '+')
					tmp->plus = 1;
				else if (fmt[i] == '0')
					tmp->z_pad = 1;
				else if (fmt[i] == '#')
					tmp->alternate = 1;
				else if (fmt[i] == ' ')
					tmp->space = 1;
				else if (fmt[i] == '*' && tmp->width != -10)
					tmp->width = -10;
				else if (fmt[i] == '*' && tmp->width == -10)
					tmp->accuracy = -10;
				else if (ft_isdigit(fmt[i]))
					ft_get_width(fmt, &i, tmp);
				else if (fmt[i] == '.')
					ft_get_accuracy(fmt, &i, tmp);
				else if (ft_is_modifier(&(fmt[i])))
					ft_get_greatest_modifier(fmt, &i, tmp);
				i++;
			}
			if (ft_is_format(fmt[i]))
				ft_get_fmt(tmp, fmt[i]);
			else if (!fmt[i])
				tmp->incomplete = 1;
			else
				ft_wildcard(tmp, fmt, &i);
			tmp->end_index = i;
		}
		i++;
	}
	return (args->next);
}

int		ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			state_value;
	T_LIST		*args_data;
	char		*result;

	va_start(args, fmt);
	result = ft_strdup(fmt);
	state_value = ft_check_fmt(fmt);
	args_data = ft_get_args(ft_strdup(fmt));
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
	ft_free_list(&args_data);
	return (state_value ? ft_strlen(result) : -1);
}
