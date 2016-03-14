/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:03:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 17:41:21 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_H
# define _LEM_IN_H
# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <errno.h>

typedef struct		s_ant
{
	int				number;
	struct s_room	*actual;
	struct s_path	*path;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	struct s_room	**links;
	int				is_end;
	int				is_start;
	int				is_full;
}					t_room;

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*next;
}					t_path;

t_ant				*ft_create_ant(int number);
t_room				ft_create_room(char *name, int is_end, int is_start);
t_path				*ft_create_path(t_room *room);
t_path				*ft_build_path(t_room *room, t_path *actual_path, t_path **all_paths);
void				ft_link_room(t_room *rooma, t_room *roomb);
int					ft_path_is_free(t_path *path, t_path **all_paths);
int					ft_iterate(t_ant **ants, t_path **paths);
t_ant				**ft_get_ants(char ***args, int *number_of_ants);
char				**ft_read_file(int fd);
t_room				**ft_get_rooms(char	***args, int *len);
void				ft_link_rooms(t_room **rooms, char **args, int len);
t_path				**ft_find_paths(t_room **rooms);
void				ft_core(t_room **rooms, t_ant **ants);
void				ft_free_everything(t_path **paths, t_room **rooms, t_ant **ants);
void				ft_print_move(t_ant *ant);
void				ft_block(char *string);
int					ft_path_len(t_path *path);
t_path				*ft_min_path(t_path *path_one, t_path *path_two);

#endif
