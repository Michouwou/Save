/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:19:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/14 12:24:44 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

t_path  **ft_find_paths(t_room **rooms)
{
    t_path  **result;
    t_room  *start;
    int     i;
    
    i = 0;
    while (rooms[i]->name)
    {
        if (rooms[i]->is_start)
            start = rooms[i];
        i++;
    }
    result = (t_path**)malloc(sizeof(t_path*) * i);
    result[i = 0] = ft_build_path(start, *result, result);
    i = 1;
    while ((result[i] = ft_build_path(start, result[i], result)) != NULL)
        i++;
    return (result);
}
