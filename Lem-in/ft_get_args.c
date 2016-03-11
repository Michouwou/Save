/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/11 10:38:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant		**ft_find_ants(char **args)
{
	int		tmp;
	int		i;
	t_ant	**ants;

	i = 0;
	if ((tmp = ft_atoi(args[0])) > 0)
	{
		ants = (t_ant**)malloc(sizeof(t_ant*) * (tmp + 1));
		while (i < tmp)
		{
			ants[i] = ft_make_ant(i + 1);
			i++;
		}
		ants[i] = NULL;
	}
	else
		ants = NULL;
	return (ants);
}

t_room		**ft_find_rooms(char **args, t_room **start, t_room **end)
{
	int		i;
	t_room	**rooms;
	char	**tmp;

	i = 0;
	while (args[i] && !ft_strchr(args[i], '-'))
		i++;
	rooms = (t_room**)malloc(sizeof(t_room*) * (i + 1));
	i = 0;
	while (args[i] && !ft_strchr(args[i], '-'))
	{
		tmp = ft_strsplit(args[i], ' ');
		if (ft_strstr(tmp, "##")
		rooms[i] = ft_make_room(tmp[0]);
		i++;
	}
	rooms[i] = NULL;
	return (rooms);
}

static void ft_increase_tab(char ***to_up, int len)
{
    char    **tmp;
    int     i;
    
    i = 0;
    tmp = *to_up;
    *to_up = (char**)malloc(sizeof(char*) * len + 6);
    while (i < len)
    {
        (*to_up)[i] = ft_strcpy(*to_up[i], tmp[i]);
        i++;
    }
    i = 0;
    while (i < len)
        free(tmp[i++]);
    free(tmp);
}

char        **ft_get_args(char *filename, int *lines)
{
    int     fd;
    int     status;
    char    **result;
    int     line_num;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        ft_block();
    status = 1;
    line_num = 0;
    result = (char**)malloc(sizeof(char*) * 6);
    while (status)
    {
        status = get_next_line(fd, &(result[line_num]));
        ++line_num;
        if (!(line_num % 6))
            ft_increase_tab(&result, line_num);
        if (status == -1)
            ft_block();
    }
    *lines = line_num;
    return (result);
}
