/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:15:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/12 16:15:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_rooms(char **args)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (!ft_strchr(args[i], '-'))
	{
		if (!ft_strchr(args[i], '#'))
			num++;
		i++;
	}
	printf("On compte les pieces pour pouvoir en allouer le bon nombre\n");
	return (num);
}

void	ft_get_rooms(char ***args, int *number_of_rooms, t_room ***result)
{
	int		i;
	char	**tmp;
	int		flags[2];

	*result = (t_room**)malloc(sizeof(t_room*) * (count_rooms(*args) + 1));
	i = 0;
	while (!ft_strchr((*args)[i], '-'))
	{
		tmp = ft_strsplit((*args)[i], ' ');
		if (!ft_strcmp(tmp[0], "##start") || !ft_strcmp(tmp[0], "##end"))
			flags[!ft_strcmp(tmp[0], "##start") ? 0 : 1] = 1;
		else if (!ft_strchr(tmp[0], '#'))
		{
			(*result)[*number_of_rooms] = ft_create_room(tmp[0], flags[1], flags[0]);
			flags[0] = 0;
			flags[1] = 0;
			*number_of_rooms += 1;
		}
		free(tmp);
		i++;
	}
	printf("On vient de creer les differentes pieces\n");
	(*result)[*number_of_rooms] = ft_create_room(NULL, 0, 0);
	*args += i;
}
