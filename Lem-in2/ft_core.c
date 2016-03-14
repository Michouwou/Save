/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:07 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 12:21:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_core(t_room **rooms, t_ant **ants)
{
    t_path  **paths;
    int     status;
    
    paths = ft_find_paths(rooms);
    status = 1;
    while (status)
        status = ft_iterate(ants, paths);
    ft_free_everything(paths, rooms, ants);
}
