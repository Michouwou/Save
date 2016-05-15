/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/15 15:51:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	**ft_find_paths(t_room **rooms)
{
	t_path	**result;
	t_room	*start;
	int		i;

	i = 0;
	start = NULL;
	while (rooms[i] && rooms[i]->name)
	{
		if (rooms[i]->is_start)
		{
			start = rooms[i];
			break ;
		}
		i++;
	}
	if (!rooms[i] || !start)
		ft_block("You didn't build ANY starting room? You dumb!!!\n");
	i = 0;
	if (!start->links)
		ft_block("Starting room is a dead-end, shit!\n");
	while (start->links[i] && start->links[i]->name)
		i++;
	result = (t_path**)malloc(sizeof(t_path*) * i + 1);
	while (i >= 0)
	{
		result[i] = NULL;
		i--;
	}
	result[0] = ft_build_path(start, result[0], result);
	i = 0;
	while (result[i] != NULL)
	{
		i++;
		result[i] = ft_build_path(start, result[i], result);
	}
	return (result);
}
