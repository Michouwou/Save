/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:04:13 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/26 11:44:29 by mlevieux         ###   ########.fr       */
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

static void	care_rooms(t_room **rooms)
{
	int	i;

	i = 0;
	while (rooms[i])
	{
		free(rooms[i]->name);
		free(rooms[i]->links);
		free(rooms[i++]);
	}
}

void		ft_free_everything(t_path **paths, t_room **rooms, t_ant **ants)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("On est dans ft_free_everything\n");
	care_paths(paths);
	while (ants[i])
		free(ants[i++]);
	free(ants);
	i = 0;
	while (rooms[i])
	{
		j = 0;
		ft_printf("Avant la boucle\n");
		while (rooms[i]->links && rooms[i]->links[j] &&
			rooms[i]->links[j]->name)
		{
			ft_printf("rooms[i]->links[j]->name : %s\n", rooms[i]->links[j]->name);
			j++;
		}
		ft_printf("Apres la boucle\n");
		free(rooms[i]->links ? rooms[i]->links[j] : NULL);
		ft_printf("Apres le free\n");
		i++;
	}
	care_rooms(rooms);
	free(rooms);
	ft_printf("On y est plus\n");
}
