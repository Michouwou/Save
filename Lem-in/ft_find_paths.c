/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/16 14:24:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	**build_result(t_path **result, t_room *start, int i)
{
	t_path	*tmp;

	result = (t_path**)malloc(sizeof(t_path*) * (i + 1));
	while (i >= 0)
	{
		result[i] = NULL;
		i--;
	}
	result[0] = ft_build_path(start, result[0], result);
	i = 0;
	while (result[i] != NULL)
	{
		tmp = result[i];
		while (tmp)
			tmp = tmp->next;
		i++;
		result[i] = ft_build_path(start, result[i], result);
	}
	return (result);
}

t_path			**ft_find_paths(t_room **rooms)
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
		ft_block("You didn't build ANY starting room? You dumb!!!");
	i = 0;
	if (!start->links)
		ft_block("Starting room is a dead-end, shit!");
	while (start->links[i] && start->links[i]->name)
		i++;
	return (build_result(result, start, i));
}
