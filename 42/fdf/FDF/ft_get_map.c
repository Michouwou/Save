/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:00:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/20 12:16:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void	extend_map(t_line **map, int k)
{
	t_line	*ret;
	int		i;

	ret = (t_line*)malloc(sizeof(t_line) * k + 1);
	i = 0;
	while (i < k)
	{
		ret[i].x = (*map)[i].x;
		ret[i].y = (*map)[i].y;
		ret[i].z = (*map)[i].z;
		ret[i].z_origin = (*map)[i].z_origin;
		i++;
	}
	*map = ret;
}

t_line	ft_get_line(char *tmp, int *n_per_line, int y)
{
	char	**tmp2;
	t_line	ret;
	int		k;

	k = 0;
	tmp2 = ft_strsplit(tmp, ' ');
	while (tmp2[k])
		k++;
	ret.x = (int*)malloc(sizeof(int) * (k + 1));
	ret.y = (int*)malloc(sizeof(int) * (k + 1));
	ret.z = (int*)malloc(sizeof(int) * (k + 1));
	ret.z_origin = (int*)malloc(sizeof(int) * (k + 1));
	k = 0;
	while (tmp2[k])
	{
		ret.x[k] = k + 1;
		ret.y[k] = y + 1;
		ret.z[k] = ft_atoi(tmp2[k]);
		ret.z_origin[k] = ret.z[k];
		k++;
	}
	if (*n_per_line == 0)
		*n_per_line = k;
	else if (*n_per_line != k)
		exit(0);
	return (ret);
}

t_line	*ft_get_map(int fd, int *nb_lines, int *n_per_line)
{
	t_line	*map;
	char	*tmp;
	int		k;

	map = NULL;
	tmp = NULL;	
	*n_per_line = 0;
	k = 0;
	while (get_next_line(fd, &tmp) == 1)
	{
		extend_map(&map, k);
		map[k] = ft_get_line(tmp, n_per_line, k);
		k++;
	}
	*nb_lines = k;
	return (map);
}
