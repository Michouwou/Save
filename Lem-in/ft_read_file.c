/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:27:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/06/06 09:45:15 by mlevieux         ###   ########.fr       */
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

static int	func_one(char *tmp, int *i, t_ant ***ants, int *number_of_ants)
{
	ft_printf("On entre dans func_one\n");
	if (!tmp[0] && *i != 3)
		ft_block("Empty lines are forbidden, you fool'");
	if ((*i == 0 && (!tmp[0] || (!ft_is_number(tmp) && tmp[0] != '#'))) ||
		(*i != 0 && !*number_of_ants))
		ft_block("Your arguments do not begin with the number of ants");
	ft_putendl(tmp);
	if (tmp[0] != '#' && *i == 0)
	{
		ft_get_ants(tmp, number_of_ants, ants);
		*i = 1;
		ft_printf("On sort de func_one\n");
		return (1);
	}
	ft_printf("On sort de func_one\n");
	return (0);
}

static int	func_two(char *tmp, int flags[], t_room ***rooms, int *nrooms)
{
	ft_printf("On entre dans func_two\n");
	if (tmp[0] != '#' && (!ft_strchr(tmp, '-') || ft_strchr(tmp, ' ')) &&
		flags[0] < 3)
	{
		ft_printf("func_two --> premiere comdition\n");
		ft_get_rooms(tmp, nrooms, rooms, &(flags[1]));
		flags[0] = 2;
		ft_printf("On sort de func_two\n");
		return (1);
	}
	else if (tmp[0] != '#' && ft_strchr(tmp, '-') && flags[0] > 1)
	{
		ft_printf("func_two --> deuxieme condition\n");
		flags[1] = ft_links_rooms(tmp, *rooms);
		if (!flags[1] && flags[0] < 3)
			ft_block("No links? Ants can't fly!");
		else if (!flags[1])
			return (-1);
		else if (flags[2] != 3)
			ft_block("Either start or end is missing!!!");
		flags[0] = 3;
		ft_printf("On sort de func_two\n");
		return (1);
	}
	ft_printf("On sort de func_two\n");
	return (0);
}

static void	get_commands(char *tmp, int flags[])
{
	ft_printf("On entre dans get_commands\n");
	if (flags[0] == 0)
		ft_block("Your arguments do not begin with the number of ants");
	if (flags[1])
		ft_block("Two following commands are forbidden, what did you think?!");
	flags[1] = (tmp[2] == 's') ? 1 : 2;
	flags[0] = 2;
	if (flags[2] == 0)
		flags[2] = flags[1] == 1 ? 1 : 2;
	else if (flags[2] == 1 || flags[2] == 3)
	{
		if (flags[1] == 1)
			ft_block("The project said there's one end and one start");
		flags[2] = 3;
	}
	else if (flags[2] == 2 || flags[2] == 3)
	{
		if (flags[1] == 2)
			ft_block("The project said there's one end and one start");
		flags[2] = 3;
	}
	ft_printf("On sort de func_two\n");
}

void		ft_read(t_room ***rooms, t_ant ***ants, int *nrooms, int *nants)
{
	char	*tmp;
	int		flags[3];
	int		mem;

	tmp = NULL;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (get_next_line(0, &tmp) == 1)
	{
		ft_printf("On entre dans la boucle\n");
		if ((mem = func_one(tmp, &(flags[0]), ants, nants)) == 0)
			mem = func_two(tmp, flags, rooms, nrooms);
		if (!mem && (!ft_strcmp(tmp, "##start") || !ft_strcmp(tmp, "##end")) &&
			flags[0] < 3)
			get_commands(tmp, flags);
		ft_printf("On a fini les conditions\n");
		mem = !mem && tmp[0] != '#' ? -1 : mem;
		free(tmp);
		ft_printf("On a free tmp\n");
		if (mem == -1)
			return ;
		ft_check_coordinates(*rooms, *nrooms);
		ft_printf("On vient de check les coordonnees\n");
	}
	ft_printf("On va sortir\n");
	free(tmp ? tmp : NULL);
	if (!flags[1])
		ft_block("I think either your forgot your links or your rooms");
}
