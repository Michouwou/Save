/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coordinates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:25:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/24 14:43:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	part_two(t_room **rooms, int i, int j)
{
	if (((rooms[i]->is_start && rooms[i + j]->is_end) ||
			(rooms[i]->is_end && rooms[i + j]->is_start)) &&
		!ft_strcmp(rooms[i]->name, rooms[i + j]->name))
		ft_block("Please make the difference between START and END");
	else if (((rooms[i]->is_start && rooms[i + j]->is_start) ||
			(rooms[i]->is_end && rooms[i + j]->is_end)) &&
		ft_strcmp(rooms[i]->name, rooms[i + j]->name))
		ft_block("The project said there's one start and one end :/");
}

void	ft_check_coordinates(t_room **rooms, int number_of_rooms)
{
	int		i;
	int		j;

	i = 0;
	while (i + 1 < number_of_rooms)
	{
		j = 1;
		while (i + j < number_of_rooms)
		{
			if (rooms[i]->x == rooms[i + j]->x &&
				rooms[i]->y == rooms[i + j]->y &&
				ft_strcmp(rooms[i]->name, rooms[i + j]->name))
				ft_block("You cannot have two rooms at the same place.");
			else if (!ft_strcmp(rooms[i]->name, rooms[i + j]->name) &&
				(rooms[i]->x != rooms[i + j]->x ||
					rooms[i]->y != rooms[i + j]->y ||
					rooms[i]->is_start != rooms[i + j]->is_start ||
					rooms[i]->is_end != rooms[i + j]->is_end))
				ft_block("Two different rooms can't have the same name!");
			else
				part_two(rooms, i, j);
			j++;
		}
		i++;
	}
}
