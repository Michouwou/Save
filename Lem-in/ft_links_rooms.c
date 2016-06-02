/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:28:37 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/30 17:38:18 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	**init(t_room **tmp_one, t_room **tmp_two, char *args)
{
	char	**res;
	int		i;
	int		dash;

	i = 0;
	dash = 0;
	while (args[i])
	{
		if (args[i] == '-')
			dash++;
		i++;
	}
	if (dash > 1)
		return (NULL);
	*tmp_one = NULL;
	*tmp_two = NULL;
	res = ft_strsplit(args, '-');
	return (res);
}

static void	get_rooms(t_room **rooms, t_room **one, t_room **two, char **link)
{
	int		i;

	i = 0;
	if (!link || !link[0] || !link[1])
		return ;
	while (rooms[i]->name && !(*one && *two))
	{
		if (!ft_strcmp(rooms[i]->name, link[0]))
			*one = rooms[i];
		if (!ft_strcmp(rooms[i]->name, link[1]))
			*two = rooms[i];
		i++;
	}
}

static int	final_cond(t_room *one, t_room *two, char **links)
{
	if (!links || !links[0] || !links[1])
		return (0);
	free(links[0]);
	free(links[1]);
	free(links);
	if (one && two)
	{
		ft_link_room(one, two);
		return (1);
	}
	return (0);
}

int			ft_links_rooms(char *line, t_room **rooms)
{
	t_room	*tmp_room_one;
	t_room	*tmp_room_two;
	char	**tmp_link;

	tmp_link = init(&tmp_room_one, &tmp_room_two, line);
	if (!tmp_link)
		return (0);
	get_rooms(rooms, &tmp_room_one, &tmp_room_two, tmp_link);
	if (!final_cond(tmp_room_one, tmp_room_two, tmp_link))
		return (0);
	return (1);
}
