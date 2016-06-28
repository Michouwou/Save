/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:26:39 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/23 16:30:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*ft_map_cpy(t_line *map, int nb_lines, int n_per_line)
{
	int		i;
	int		j;
	t_line	*ret;

	ret = (t_line*)malloc(sizeof(t_line) * nb_lines);
	i = 0;
	while (i < nb_lines)
	{
		j = 0;
		ret[i].x = (int*)malloc(sizeof(int) * n_per_line);
		ret[i].y = (int*)malloc(sizeof(int) * n_per_line);
		ret[i].z = (int*)malloc(sizeof(int) * n_per_line);
		ret[i].z_origin = (int*)malloc(sizeof(int) * n_per_line);
		while (j < n_per_line)
		{
			ret[i].x[j] = map[i].x[j];
			ret[i].y[j] = map[i].y[j];
			ret[i].z[j] = map[i].z[j];
			ret[i].z_origin[j] = map[i].z_origin[j];
			j++;
		}
		i++;
	}
	return (ret);
}
