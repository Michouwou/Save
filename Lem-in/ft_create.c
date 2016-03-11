/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/11 11:50:24 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant   *ft_make_ant(int number)
{
    t_ant *new;
    
    new = (t_ant*)malloc(sizeof(t_ant));
    new->actual = (t_room*)malloc(sizeof(t_room));
    new->path = (t_room**)malloc(sizeof(t_room*));
    *(new->path) = (t_room*)malloc(sizeof(t_room));
    return (new);
}

t_room  *ft_make_room(char *name, int command)
{
    t_room  *new;
    
    new = (t_room*)malloc(sizeof(t_room));
    new->links = (t_room**)malloc(sizeof(t_room*));
    *(new->links) = NULL;
    new->is_end = (command == 2) ? 1 : 0;
	new->is_start = (command == 1) ? 1 : 0;
    new->name = ft_strnew(ft_strlen(name));
    new->name = ft_strcpy(new->name, name);
    new->name = NULL;
}
