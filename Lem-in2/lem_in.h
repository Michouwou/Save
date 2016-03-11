/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:03:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/11 15:15:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_H
# define _LEM_IN_H
# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>

typedef struct		s_ant
{
	int				number;
	struct s_room	*actual;
	struct s_path	*path;
};					t_ant

typedef struct		s_room
{
	char			*name;
	struct s_room	**links;
	int				is_end;
	int				is_start;
	int				is_full;
};					t_room

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*next;
};					t_path

t_ant		*ft_create_ant(int number);
t_room		*ft_create_room(char *name, int is_end, int is_start);
t_path		*ft_create_path(t_room *room);
t_path		*ft_build_path(t_room *room);
void		ft_link_room(t_room *rooma, t_room *roomb);
int			ft_path_is_free(t_path *path);
void		ft_parse(char **args, t_room **rooms, t_ant **ants);
void		ft_iterate(t_ant **ants, t_path **paths);
t_ant		**ft_get_ants(char **args);
char		**ft_read_file(int fd);
t_room		**ft_get_rooms(char	**args);


#endif
