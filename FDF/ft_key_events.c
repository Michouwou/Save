/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 14:18:23 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/23 16:34:54 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_events(int keycode, t_mlx *ptr)
{
	printf("Keycode = %d\n", keycode);
	if (keycode == 123 || keycode == 124)
	{
		mlx_clear_window(ptr->core, ptr->win);
		ft_translate_x(ptr, keycode == 124 ? -1 : 1);
	}
	if (keycode == 125 || keycode == 126)
	{
		mlx_clear_window(ptr->core, ptr->win);
		ft_translate_y(ptr, keycode == 125 ? -1 : 1);
	}
	if (keycode == 83 || keycode == 86)
	{
		mlx_clear_window(ptr->core, ptr->win);
		ft_rotate_x(ptr->map, ptr->nb_lines, ptr->n_per_line, keycode == 83 ? 1 : -1);
		ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	}
	if (keycode == 84 || keycode == 87)
	{
		mlx_clear_window(ptr->core, ptr->win);
		ft_rotate_y(ptr->map, ptr->nb_lines, ptr->n_per_line, keycode == 84 ? 1 : -1);
		ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	}
	if (keycode == 85 || keycode == 88)
	{
		mlx_clear_window(ptr->core, ptr->win);
		ft_rotate_z(ptr->map, ptr->nb_lines, ptr->n_per_line, keycode == 85 ? 1 : -1);
		ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	}
	if (keycode == 69 || keycode == 78)
	{
		mlx_clear_window(ptr->core, ptr->win);
		ft_zoom(ptr, keycode == 69 ? 1 : -1);
		ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	}
	if (keycode == 36)
	{
		ptr->map = ft_map_cpy(ptr->map_origin, ptr->nb_lines, ptr->n_per_line);
		ft_transform(ptr->map, ptr->nb_lines, ptr->n_per_line);
		mlx_clear_window(ptr->core, ptr->win);
		ft_draw_map(ptr, ptr->nb_lines, ptr->n_per_line, ptr->map);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}
