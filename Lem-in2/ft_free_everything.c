/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:04:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 13:25:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_everything(t_path **paths, t_room **rooms, t_ant **ants)
{
	int i;

	i = 0;
	while (ants[i]->number > -1)
		free(ants[i++]);
	free(ants);
	i = 0;
	while (rooms[i]->name)
		free(rooms[i++]);
	free(rooms);
	while (paths[i])
	{
		while (paths[i])
		{
			free(paths[i++]);
			paths[i] = paths[i]->next;
		}
		i++;
	}
	free(paths);
}
