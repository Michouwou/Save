/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     ft_lem_len(t_room *room)
{
    t_room  *tmp;
    int     len;
    int     i;
    
    len = 0;
    i = 0;
    tmp = room;
    while (room->links[i])
    {
        len = len + ft_lem_len(room->links[i]);
        i++;
    }
    return (len);
}