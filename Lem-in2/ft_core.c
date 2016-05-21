/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:07 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/16 14:25:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_core(t_room **rooms, t_ant **ants, int num_ants)
{
	t_path	**paths;
	int		status;

	paths = ft_find_paths(rooms);
	if (!paths[0])
		ft_block("There is apparently no way to cross the ant-hill...");
	ft_paths_coeff(paths, num_ants);
	status = 1;
	while (status)
		status = ft_iterate(ants, paths);
	ft_free_everything(paths, rooms, ants);
}
