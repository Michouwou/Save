/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define _LEM_IN_H
# include <stdlib.h>
# include "libftprintf.h"
# include "libft.h"
# include <stddef.h>

typedef struct  s_room
{
    struct s_room   **links;
    char            *name;
    int             is_end;
}               t_room;

typedef struct  s_ant
{
    t_room          *actual;
    t_room          **path;
}               t_ant;

typedef struct  s_path
{
    t_room          *node;
    struct s_path   *next;
}

void    ft_display_state(t_ant *ants, t_room *rooms);
void    ft_build_path(t_ant *ants, t_room *rooms);
t_ant   *ft_get_ants(char **ants, int num);
t_room  *ft_get_rooms(char **rooms, int num);
void    ft_iterate(t_ant **ants, t_room **rooms);
void    ft_block();
t_ant   *ft_make_ant(char *name);
t_room  *ft_make_room(int number);
t_room  *ft_smallest_path(t_room *rooms);
void    ft_move(t_ant *ants);

#endif