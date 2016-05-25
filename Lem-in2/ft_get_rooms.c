/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:15:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/25 16:59:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_rooms(char **args)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (args[i] && !ft_strchr(args[i], '-'))
	{
		if (!ft_strchr(args[i], '#'))
			num++;
		i++;
	}
	return (num);
}

static void	new_room(char **tmp, t_room ***result, int *number, int flags[])
{
	(*result)[*number] = ft_create_room(tmp, flags[1],
			flags[0]);
	flags[0] = 0;
	flags[1] = 0;
	*number += 1;
}

void		ft_get_rooms(char ***args, int *number_of_rooms, t_room ***result)
{
	int		i;
	char	**tmp;
	int		flags[2];

	if ((i = count_rooms(*args)) == 0)
		return ;
	*result = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	i = 0;
	flags[0] = 0;
	flags[1] = 0;
	while ((*args)[i] && !ft_strchr((*args)[i], '-'))
	{
		tmp = ft_strsplit((*args)[i], ' ');
		if (!ft_strcmp(tmp[0], "##start") || !ft_strcmp(tmp[0], "##end"))
			flags[!ft_strcmp(tmp[0], "##start") ? 0 : 1] = 1;
		else if (!ft_strchr(tmp[0], '#'))
			new_room(tmp, result, number_of_rooms, flags);
		if (tmp[0] && tmp[1] && tmp[2])
			free(tmp[2]);
		if (tmp[0] && tmp[1])
			free(tmp[1]);
		if (tmp[0])
			free(tmp[0]);
		free(tmp);
		i++;
	}
	(*result)[*number_of_rooms] = ft_create_room(NULL, 0, 0);
	ft_check_coordinates(*result, *number_of_rooms);
}
