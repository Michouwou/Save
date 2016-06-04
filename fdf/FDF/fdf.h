/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:28:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/24 11:38:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <stdlib.h>
# include "mlx.h"
# include "get_next_line.h"

# define WIN_H 1300
# define WIN_W 2000

typedef struct	s_line
{
	int			*x;
	int			*z;
	int			*z_origin;
	int			*y;
}				t_line;

typedef struct	s_mlx
{
	void		*core;
	void		*win;
	t_line		*map;
	t_line		*map_origin;
	int			nb_lines;
	int			n_per_line;
}				t_mlx;

void			ft_zoom(t_mlx *ptr, int sense);
void			ft_draw_line(int p1[], int p2[], t_mlx *ptr);
void			ft_transform(t_line *lines, int nb, int n_);
void			ft_draw_map(t_mlx *ptr, int nb, int n_, t_line *lines);
t_line			*ft_get_map(int fd, int *nb_lines, int *n_per_line);
char			**ft_read_map(int fd);
void			ft_core(t_mlx *mlx, t_line *map);
int				ft_get_color(int z);
int				ft_key_events(int keycode, t_mlx *ptr);
void			ft_translate_x(t_mlx *ptr, int sense);
void			ft_translate_y(t_mlx *ptr, int sense);
void			ft_rotate_x(t_mlx *ptr, int code);
void			ft_rotate_y(t_mlx *ptr, int code);
void			ft_rotate_z(t_mlx *ptr, int code);
t_line			*ft_map_cpy(t_line *map, int nb_lines, int n_per_line);

#endif
