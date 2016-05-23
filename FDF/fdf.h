/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:28:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/23 14:20:35 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <stdlib.h>
# include <stdio.h>
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
}				t_mlx;

void	ft_draw_line(int p1[], int p2[], t_mlx *ptr);
void	ft_transform(t_line *lines, int nb, int n_);
void	ft_draw_map(t_mlx *ptr, int nb, int n_, t_line *lines);
t_line	*ft_get_map(int fd, int *nb_lines, int *n_per_line);
char	**ft_read_map(int fd);
void	ft_core(t_mlx *mlx, t_line *map);
int		ft_get_color(int z);
int		ft_key_events(int keycode, t_mlx *ptr);

#endif
