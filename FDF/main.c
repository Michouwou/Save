/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:44:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/23 14:23:23 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	t_line	*ret;
	t_mlx	*ptr;
	int		nb_lines;
	int		n_per_line;

	ptr = (t_mlx*)malloc(sizeof(t_mlx));
	fd = open(argv[1], O_RDONLY);
	ret = ft_get_map(fd, &nb_lines, &n_per_line);
	ft_transform(ret, nb_lines, n_per_line);
	ptr->core = mlx_init();
	ptr->win = mlx_new_window(ptr->core, WIN_W, WIN_H, "FDF");
	ft_draw_map(ptr, nb_lines, n_per_line, ret);
	mlx_clear_window(ptr->core, ptr->win);
	mlx_key_hook(ptr->win, ft_key_events, ptr);
	//mlx_expose_hook(ptr->win, ft_redraw, ptr);
	mlx_loop(ptr->core);
	close(fd);
	return (0);
}
