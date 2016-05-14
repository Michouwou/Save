/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:04:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/13 16:41:10 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_everything(t_path **paths, t_room **rooms, t_ant **ants)
{
	int		i;
	t_path	*tmp;

	i = 0;
	while (ants[i])
		free(ants[i++]);
	free(ants);
	i = 0;
	while (rooms[i]->name)
		free(rooms[i++]);
	free(rooms);
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
