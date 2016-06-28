/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:44:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/02 10:20:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	t_mlx	*ptr;

	if (argc != 2)
		exit(0);
	ptr = (t_mlx*)malloc(sizeof(t_mlx));
	fd = open(argv[1], O_RDONLY);
	ptr->map = ft_get_map(fd, &(ptr->nb_lines), &(ptr->n_per_line));
	close(fd);
	ptr->map_origin = ft_map_cpy(ptr->map, ptr->nb_lines, ptr->n_per_line); 
	ft_transform(ptr->map, ptr->nb_lines, ptr->n_per_line);
	ptr->core = mlx_init();
	mlx_do_key_autorepeaton(ptr->core);
	ptr->win = mlx_new_window(ptr->core, WIN_W, WIN_H, "FDF");
	ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	mlx_key_hook(ptr->win, ft_key_events, ptr);
	mlx_loop(ptr->core);
	return (0);
}
