// HEADER

#include "lem_in.h"

static int	room_does_not_appear(t_room *room, t_path *actual_path)
{
	t_path	*tmp;

	tmp = actual_path;
	if (tmp && room && room->name)
		while (tmp)
		{
			if (!ft_strcmp(tmp->room->name, room->name))
				return (0);
			tmp = tmp->next;
		}
	return (1);
}

static int	no_possibility(t_room **rooms, t_path *actual_path)
{
	int i;
	
	i = 0;
	while (rooms && rooms[i] && rooms[i]->name && !room_does_not_appear(rooms[i], actual_path))
		i++;
	if (rooms && room_does_not_appear(rooms[i], actual_path))
		return (0);
	return (1);
}

t_path	*ft_build_path(t_room *room, t_path *actual_path, t_path **all_paths)
{
	t_path	*tmp;
	t_path	*result;
	int		i;

	tmp = actual_path;
	ft_printf("room : %s, actual_path : %s\n", room->name, actual_path ? actual_path->room->name : "NULL");
	if (room->is_end)
		return (ft_create_path(room));
	ft_printf("C'est bon\n");
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
		actual_path = ft_create_path(room);
	else
		tmp->next = ft_create_path(room);
	if (!room->is_end && no_possibility(room->links, actual_path))
		return (NULL);
	i = 0;
	result = NULL;
	tmp = tmp->next ? tmp->next : tmp;
	while (room && room->links && room->links[i])
	{
		tmp->next = ft_build_path(room->links[i], actual_path, all_paths);
		if (ft_path_is_free(tmp, all_paths))
			result = ft_min_path(tmp, result);
		i++;
	}
	if (result)
		return (result);
	else
		return (NULL);
}