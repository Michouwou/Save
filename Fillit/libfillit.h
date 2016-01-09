/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:37:09 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 15:46:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFILLIT_H
# define _LIBFILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stddef.h>
# define MAX_LENGTH 104

typedef struct	s_point
{
	int		x;
	int		y;
	int		id_form;
}				t_point;

typedef struct	s_form
{
	t_point	*origin;
	t_point *p2;
	t_point	*p3;
	t_point	*p4;
	int		id_form;
}				t_form;

typedef struct	s_superform
{
	t_point		*points;
}				t_superform;

int				ft_check_format(char *t, char *file_name);
int				ft_check_filling(char *t, char *file_name);
int				ft_launch_check(char *file_name);
t_point			*ft_new_point(int x, int y, int id);
t_form			*ft_new_form(int id_form);
void			ft_form_add_point(t_form *form, t_point *point);
int				ft_max(int x, int y);
t_point			*ft_point_sum(t_point *point1, t_point *point2);
t_superform		*ft_new_superform();
void			ft_add_form(t_superform *super, t_form *form, t_point *origin);
int				ft_isempty(t_superform *super, int x, int y);
t_superform		*ft_get_forms(char *file_name, char **char_tmp);
void			ft_add_first_form(t_superform *super, t_form *to_add);
int				ft_match(t_superform *prev, t_form *form, t_point *origin,
					int min_tab);
int				ft_min(int x, int y);
void			ft_display(t_superform *solution);
int				ft_count_forms(t_superform **total);
int				ft_form_is_valid(t_form *form);
int				ft_find_square_len(t_superform *super);
void			ft_putchar(char c);
t_superform		*ft_core(t_superform *total);
t_form			*ft_convert(t_superform *super, int id);
void			ft_main(char *file_name);
void			ft_erase_form(t_superform *result, int form);
int				ft_resolve(t_superform *total, int min_tab, t_superform *result,
					int form);
int				ft_min_tab(int nb_forms);
void			ft_error();

#endif
