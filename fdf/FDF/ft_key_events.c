/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 14:18:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/02 10:24:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_events(int keycode, t_mlx *ptr)
{
	mlx_clear_window(ptr->core, ptr->win);
	if (keycode == 123 || keycode == 124)
		ft_translate_x(ptr, keycode == 124 ? -1 : 1);
	if (keycode == 125 || keycode == 126)
		ft_translate_y(ptr, keycode == 125 ? -1 : 1);
	if (keycode == 83 || keycode == 86)
		ft_rotate_x(ptr, keycode == 83 ? 1 : -1);
	if (keycode == 84 || keycode == 87)
		ft_rotate_y(ptr, keycode == 84 ? 1 : -1);
	if (keycode == 85 || keycode == 88)
		ft_rotate_z(ptr, keycode == 85 ? 1 : -1);
	if (keycode == 69 || keycode == 78)
		ft_zoom(ptr, keycode == 69 ? 1 : -1);
	if (keycode == 36)
	{
		ptr->map = ft_map_cpy(ptr->map_origin, ptr->nb_lines, ptr->n_per_line);
		ft_transform(ptr->map, ptr->nb_lines, ptr->n_per_line);
	}
	if (keycode == 53)
		exit(0);
	ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	return (0);
}
