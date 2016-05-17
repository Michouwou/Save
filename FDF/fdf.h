/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:28:08 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/17 16:48:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <stdlib.h>
# include "mlx.h"

# define WIN_H 1500
# define WIN_W 1500

typedef struct	s_line
{
	int			*x;
	int			*z;
	int			*y;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx_core;
	void		*window;
}

void	ft_draw_line(int x1, int y1, int y1, int y2);
t_line	*ft_get_map(char **map);
char	**ft_read_map(int fd);
void	ft_core(t_mlx *mlx, t_line *map);
int		ft_get_color(int z);
void	ft_transform(t_line **map);

#endif
