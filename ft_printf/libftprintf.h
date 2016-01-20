/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:03:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/20 12:38:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H
# include <inttypes.h>
# include <stdarg.h>
# include <stdlib.h>
# include <locale.h>
#include 				<stdio.h> // DO NOT FORGET TO ERASE /!\. 
# include <unistd.h>
# include <wchar.h>
# include "libft.h"
# define T_LIST t_list_printf
# define T_ trail->type
# define INT_TYPE 'd'
# define CHAR_TYPE 'c'
# define POINTER_TYPE 'p'
# define STRING_TYPE 's'
# define WSTRING_TYPE 'S'
# define DOUBLE_TYPE 'f'
//# define NOT_YET_DEFINED '*'
# define NOT_TYPE 0

typedef struct	s_list_printf
{
	int						start_index;
	int						end_index;
	int						accuracy;
	int						width;
	//int					arg_index;
	//int					is_star;
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
void			ft_call_int(intmax_t arg, T_LIST *locate, wchar_t *result); // ?
void			ft_call_pointer(unsigned arg, T_LIST *locate, wchar_t *result); // ?
void			ft_call_char(wchar_t arg, T_LIST *locate, wchar_t *result); // ?
//void			ft_call_string(char *arg, T_LIST *locate, wchar_t *result); // ?
void			ft_call_wstring(wchar_t *arg, T_LIST *locate, wchar_t *result); // ?
void			ft_call_float(long double arg, T_LIST *locate, wchar_t *result); // ?
void			ft_putwstr(wchar_t *to_print); //OK
int				ft_wstrlen(wchar_t *wstring); // OK
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
void			ft_wbzero(wchar_t *wstring, int len); // OK
void			utf8(void); // OK
wchar_t			*ft_base(intmax_t nb, int base); // OK
void			ft_check_format(char *format); // OK
wchar_t			*ft_repstr(wchar_t *print, int start, int end,
						wchar_t *to_insert); // A revoir de A a Z!!
wchar_t			ft_char_apply_mod(T_LIST *trail, wchar_t wc); // ?
wchar_t			*ft_set_length(T_LIST *trail, wchar_t *result); // Shall work for any format!! // ???
wchar_t			*ft_wstrnew(int size); // OK
long double		ft_float_apply_mod(T_LIST *trail, long double number); // ?
wchar_t			*ft_conv_float(long double number, int accuracy); // ?
wchar_t			*ft_watoi(intmax_t number); // ?
intmax_t		ft_int_apply_mod(T_LIST *trail, intmax_t number); // ?
wchar_t			*ft_set_width(wchar_t *result, T_LIST *trail); // ?
wchar_t			*ft_apply_flag(wchar_t *result, T_LIST *trail);
//wchar_t			*ft_string_set_width(wchar_t *result, T_LIST *trail);
//wchar_t			*ft_string_apply_flag(wchar_t *result, T_LIST *trail);
wchar_t			*ft_wstring_apply_mod(T_LIST *trail, wchar_t *wstring); // ?
wchar_t			*ft_wstrcpy(wchar_t *wdest, wchar_t *wsrc); // ?
void			ft_wstrset(wchar_t *wstr, int len, char c); // ?
wchar_t			*ft_alternate(wchar_t *result, T_LIST *trail); // ?
wchar_t			*ft_wstrdup(wchar_t *wstr);
wchar_t			*ft_wstrsub(wchar_t *wstr, int i, int len);

#endif
