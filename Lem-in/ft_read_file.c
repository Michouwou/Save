/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:27:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/25 16:48:19 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_strjoin_free(char *str1, char *str2, int code)
{
	int		cursor[2];
	int		tmp[2];
	char	*result;

	cursor[0] = 0;
	cursor[1] = 0;
	tmp[0] = ft_strlen(str1);
	tmp[1] = ft_strlen(str2);
	result = ft_strnew(tmp[0] + tmp[1]);
	while (cursor[0] < tmp[0])
	{
		result[cursor[0]] = str1[cursor[0]];
		++cursor[0];
	}
	while (cursor[1] < tmp[1])
	{
		result[cursor[0] + cursor[1]] = str2[cursor[1]];
		++cursor[1];
	}
	result[cursor[0] + cursor[1]] = 0;
	free(code == 1 || code == 3 ? str1 : NULL);
	free(code == 2 || code == 3 ? str2 : NULL);
	return (result);
}

void		ft_read_file(t_room ***rooms, t_ant ***ants, int *number_of_rooms, int *number_of_ants)
{
	char	*tmp;
	int		i;
	int		flag;

	tmp = NULL;
	i = 0;
	flag = 0;
	while (get_next_line(0, &tmp) == 1)
	{
		if (!tmp[0] && i != 3)
			ft_block("Empty lines are forbidden, you fool'");
		if ((i == 0 && (!tmp[0] || (!ft_is_number(tmp) && tmp[0] != '#'))) || (i != 0 && !*number_of_ants))
			ft_block("Your arguments do not begin with the number of ants");
		else if (tmp[0] != '#' && i == 0)
		{
			ft_get_ants(tmp, number_of_ants, ants);
			i = 1;
		}
		else if (tmp[0] != '#' && !ft_strchr(tmp, '-') && i < 3)
		{
			ft_get_rooms(tmp, number_of_rooms, rooms, &flag);
			i = 2;
		}
		else if (tmp[0] != '#' && ft_strchr(tmp, '-') && i > 1)
		{
			flag = ft_links_rooms(tmp, *rooms);
			if (!flag && i < 3)
				ft_block("No links? Ants can't fly!");
			else if (!flag)
				return ;
			i = 3;
		}
		else if ((!ft_strcmp(tmp, "##start") || !ft_strcmp(tmp, "##end")) && i < 3)
		{
			flag = (tmp[2] == 's') ? 1 : 2;
			i = 2;
		}
		else if (tmp[0] != '#')
			return ;
		ft_putendl(tmp);
		free(tmp);
		ft_check_coordinates(*rooms, *number_of_rooms);
	}
	
}
