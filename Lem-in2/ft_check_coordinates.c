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
				rooms[i]->y == rooms[i + j]->y)
				ft_block("You cannot have two rooms at the same place.");
			j++;
		}
		i++;
	}
}
