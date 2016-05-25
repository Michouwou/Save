/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:04:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/25 14:18:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	care_paths(t_path **paths)
{
	t_path	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		while (paths[i])
		{
			tmp = paths[i];
			paths[i] = paths[i]->next;
			free(tmp);
		}
		i++;
	}
	free(paths);
}

void		ft_free_everything(t_path **paths, t_room **rooms, t_ant **ants)
{
	int		i;

	i = 0;
	while (ants[i])
		free(ants[i++]);
	free(ants);
	i = 0;
	while (rooms[i]->name)
	{
		free(rooms[i]->name);
		free(rooms[i]->links);
		free(rooms[i++]);
	}
	free(rooms[i]);
	free(rooms);
	care_paths(paths);
}
