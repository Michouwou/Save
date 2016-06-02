/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:15:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/30 14:19:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	increase_num_rooms(t_room ***rooms, int i)
{
	int		j;
	t_room	**tmp;

	j = 0;
	if (i % 10 == 0)
	{
		tmp = (t_room**)malloc(sizeof(t_room*) * (i + 10));
		while (j < i)
		{
			tmp[j] = (*rooms)[j];
			j++;
		}
		*rooms = tmp;
	}
}

static void	num_space(char *str)
{
	int		i;
	int		spaces;

	spaces = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces > 2)
		ft_block("Make sure there's no trailing space in your file!");
}

static void	new_room(char **tmp, t_room ***result, int *number, int *flag)
{
	int	i;

	i = 0;
	while (i < *number)
	{
		if (!ft_strcmp((*result)[i]->name, tmp[0]) &&
			(*result)[i]->x == ft_atoi(tmp[1]) &&
			(*result)[i]->y == ft_atoi(tmp[2]) &&
			((*result)[i]->is_start == (*flag == 1) ? 1 : 0 ) &&
			(*result)[i]->is_end == (*flag ==  2) ? 1 : 0)
		{
			i = -1;
			break ;
		}
		i++;
	}
	if (i != -1)
	{
		(*result)[*number] = ft_create_room(tmp, *flag == 1, *flag == 2);
		*number += 1;
	}
}

static void	for_tmp(char ***tmp)
{
	if ((*tmp)[0] && (*tmp)[1] && (*tmp)[2])
		free((*tmp)[2]);
	if ((*tmp)[0] && (*tmp)[1])
		free((*tmp)[1]);
	if ((*tmp)[0])
		free((*tmp)[0]);
	free(*tmp);
}

void		ft_get_rooms(char *line, int *number_of_rooms, t_room ***rooms, int *flag)
{
	char	**tmp;

	increase_num_rooms(rooms, *number_of_rooms);
	num_space(line);
	tmp = ft_strsplit(line, ' ');
	new_room(tmp, rooms, number_of_rooms, flag);
	for_tmp(&tmp);
	(*rooms)[*number_of_rooms] = ft_create_room(NULL, 0, 0);
}
