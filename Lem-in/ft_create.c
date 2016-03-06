/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant   *ft_make_ant(char *name)
{
    t_ant *new;
    
    new = (t_ant*)malloc(sizeof(t_ant));
    new->actual = (t_room*)malloc(sizeof(t_room));
    new->path = (t_room**)malloc(sizeof(t_room*));
    *(new->path) = (t_room*)malloc(sizeof(t_room));
    new->name = ft_strdup(name);
    new->moved = 0;
    return (new);
}

t_room  *ft_make_room(int number)
{
    t_room  *new;
    
    new = (t_room*)malloc(sizeof(t_room));
    new->content = (t_ant**)malloc(sizeof(t_ant*));
    *(new->content) = NULL;
    new->links = (t_room**)malloc(sizeof(t_room*));
    *(new->links) = NULL;
    new->name = NULL;
}