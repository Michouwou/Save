/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:00:05 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/17 16:19:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_get_map(int fd)
{
	char	**map;
	int		**ret;
	char	*tmp1;
	char	*tmp2;
	
	tmp2 = ft_strdup("");
	while (get_next_line(fd, &tmp1) == 1)
	{
		tmp2 = ft_strjoin_free(tmp2, tmp1, 3);
		tmp2 = ft_strjoin_free(tmp2, "\n", 1);
	}
	map = ft_strsplit(tmp2, '\n');
	return (map);
}
