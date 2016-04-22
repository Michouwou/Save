/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:03:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/22 10:50:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H
# include <inttypes.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"
# include <errno.h>
# include <string.h>
# define T_LIST t_list_printf
# define T_ trail->type
# define M_ t->format
# define INT_TYPE 'd'
# define CHAR_TYPE 'c'
# define POINTER_TYPE 'p'
# define STRING_TYPE 's'
# define WSTRING_TYPE 'S'
# define DOUBLE_TYPE 'f'
# define ERRNO 'E'
# define PERCENT '%'
# define NOT_TYPE 0

typedef struct	s_list_printf
{
	int						start_index;
	int						end_index;
	int						accuracy;
	int						width;
	char					type;
	char					format;
	int						z_pad;
	int						minus;
	int						plus;
	int						alternate;
	int						space;
	char					*mod;
	struct s_list_printf	*next;
}				t_list_printf;

int				ft_printf(char const *format, ...); // OK
T_LIST			*ft_find_form(char *format); // OK
wchar_t			*ft_conv_wchar(char *string); // OK
void			ft_call_int(intmax_t arg, T_LIST *locate, char **result); // ?
void			ft_call_pointer(unsigned arg, T_LIST *locate, char **result); // ?
void			ft_call_char(wchar_t arg, T_LIST *locate, char **result); // ?
void			ft_call_wstring(wchar_t *arg, T_LIST *locate, char **result); // ?
void			ft_call_float(long double arg, T_LIST *locate, char **result); // ?
void			ft_free_list(T_LIST **start); // OK
T_LIST			*ft_first_node(void); // OK
void			ft_add_knot(T_LIST **node, int location, char *format); // OK
int				ft_type_index(char *format, int location); // OK
char			ft_get_format(char *format, int location); // OK
char			ft_what_type(char format_in_knot); // OK
void			ft_get_flag(char *format, int location, T_LIST *knot); // OK
int				ft_get_width(char *format, int location); // ?
int				ft_get_accuracy(char *format, int location); // ?
char			*ft_get_mod(char *format, int start, int end); // OK
int				ft_is_flag(char flag); // OK
int				ft_is_mod(char modifier); // OK
void			ft_error(int error_code); // OK
void			utf8(void);
char			*ft_base(intmax_t nb, int base); // OK
int				ft_check_format(char *format); // OK
char			*ft_repstr(char *print, int start, int end, char *to_insert); // A revoir de A a Z!!
wchar_t			ft_char_apply_mod(T_LIST *trail, wchar_t wc); // ?
char			*ft_set_length(T_LIST *trail, char *result); // Shall work for any format!! // ???
long double		ft_float_apply_mod(T_LIST *trail, long double number); // ?
char			*ft_conv_float(long double number, int accuracy); // ?
long long int	ft_int_apply_mod(T_LIST *trail, long long int number); // ?
char			*ft_set_width(char *result, T_LIST *trail); // ?
char			*ft_apply_flag(char *result, T_LIST *trail);
wchar_t			*ft_wstring_apply_mod(T_LIST *trail, wchar_t *wstring); // ?
char			*ft_strset(char *str, int len, char c); // ?
char			*ft_alternate(char *result, T_LIST *trail); // ?
unsigned char	*ft_transfer_wchar(wchar_t c);
char			*ft_transfer_wchars(wchar_t *wstr);
void			ft_move_index(T_LIST **trail, int padding);
void			ft_round(long double *num, int accuracy);
void			ft_strtoupper(char *str);
char			*ft_conv_exp(long double number, T_LIST *trail);
void			ft_get_int(T_LIST *trail, char **print, va_list *args);
void			ft_get_star(va_list *args, T_LIST *trail);
void			ft_get_arg(T_LIST *trail, char **print, va_list *args);
void			ft_call_errno(T_LIST *trail, char **print);
void            ft_get_float(T_LIST *trail, char **print, va_list *args);
size_t			ft_wstrlen(wchar_t *wstring);
#endif
