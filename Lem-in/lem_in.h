/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:03:53 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/26 14:25:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_H
# define _LEM_IN_H

# include "libft.h"
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
	int				x;
	int				y;
}					t_room;

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*next;
	int				coeff;
}					t_path;

t_ant				*ft_create_ant(int number);
t_room				*ft_create_room(char **tab, int is_end, int is_start);
t_path				*ft_create_path(t_room *room);
t_path				*ft_build_path(t_room *room, t_path *actual_path,
		t_path **all_paths);
void				ft_link_room(t_room *rooma, t_room *roomb);
int					ft_path_is_free(t_path *path, t_path **all_paths);
int					ft_iterate(t_ant **ants, t_path **paths);
void				ft_get_ants(char *str, int *number_of_ants, t_ant ***ants);
void				ft_read_file(t_room ***rooms, t_ant ***ants,
		int *number_of_rooms, int *number_of_ants);
void				ft_get_rooms(char *line, int *number_of_rooms,
		t_room ***rooms, int *flag);
int					ft_links_rooms(char *line, t_room **rooms);
t_path				**ft_find_paths(t_room **rooms);
void				ft_core(t_room **rooms, t_ant **ants, int number_of_ants);
void				ft_free_everything(t_path **paths, t_room **rooms,
		t_ant **ants);
void				ft_print_move(t_ant *ant);
void				ft_block(char *string);
int					ft_path_len(t_path *path);
t_path				*ft_min_path(t_path *path_one, t_path *path_two);
void				ft_paths_coeff(t_path **paths, int number_of_ants);
int					ft_is_number(char *str);
void				ft_check_coordinates(t_room **rooms, int number_of_rooms);
void				ft_free_path(t_path *path);

#endif
