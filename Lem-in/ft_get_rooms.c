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

	if ((i + 1) % 10 == 0 || i == 0)
	{
		tmp = (t_room**)malloc(sizeof(t_room*) * (i + 10));
		j = 0;
		while ((*rooms) && (*rooms)[j])
		{
			tmp[j] = (*rooms)[j];
			j++;
		}
		free(i != 0 ? *rooms : NULL);
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
		if (str[i] == '-' && spaces == 0)
			ft_block("Room names can't contain dashes, that's an error");
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces > 2)
		ft_block("Make sure there's no trailing space in your args!");
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
			(((*result)[i]->is_start && *flag == 2) ||
				(!(*result)[i]->is_start && *flag != 2)) &&
			(((*result)[i]->is_end && *flag == 1) || (!(*result)[i] &&
				*flag != 1)))
		{
			i = -1;
			break ;
		}
		i++;
	}
	if (i != -1)
	{
		(*result)[*number] = ft_create_room(tmp, *flag == 2, *flag == 1);
		*number += 1;
	}
	*flag = 0;
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

void		ft_get_rooms(char *line, int *nrooms, t_room ***rooms, int *flag)
{
	char	**tmp;

	ft_printf("On entre dans ft_get_rooms\n");
	increase_num_rooms(rooms, *nrooms);
	ft_printf("On a finit increase_num_rooms\n");
	num_space(line);
	ft_printf("On a finit num_space\n");
	tmp = ft_strsplit(line, ' ');
	if ((tmp[0] && tmp[1] && (ft_strchr(tmp[1], '.') ||
		ft_strchr(tmp[1], ','))) || (tmp[0] && tmp[1] &&
		tmp[2] && (ft_strchr(tmp[2], '.') || ft_strchr(tmp[2], ','))) ||
		(tmp[1] && ft_is_number(tmp[1]) == 1 && !ft_atoi(tmp[1])) ||
		(tmp[1] && tmp[2] && ft_is_number(tmp[2]) == 1 && !ft_atoi(tmp[2])))
		ft_block("Coordinates must be representable as ints");
	ft_printf("On a finit de regarder l'integrite du nombre\n");
	new_room(tmp, rooms, nrooms, flag);
	ft_printf("On est sorti de new_room\n");
	for_tmp(&tmp);
	(*rooms)[*nrooms] = NULL;
	ft_printf("Memoire liberee!\n");
}
