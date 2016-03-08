/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_iterate(t_ant **ants, t_room **rooms)
{
    t_room  *tmp_room;
    t_ant   *tmp_ant;
    int     ant;
    
    tmp_room = *rooms;
    tmp_ant = *ants;
    room = 0;
    while ((tmp_ant[ant])->name != NULL)
    {
        ft_move_ant(&(tmp_ant[ant]), rooms);
        ant++;
    }
}