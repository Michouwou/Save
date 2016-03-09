/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/05 11:20:16 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path  *ft_build_path(t_path **existing_paths, t_room *rooms)
{
    int     i;
    int     min_path;
    t_path  *result;
    t_path  *tmp;
    
    i = 0;
    min_path = ft_lem_len(rooms);
    tmp = NULL;
    if (!rooms->links[0] && !rooms->is_end)
        return (NULL);
    if (rooms->is_end)
        return (ft_create_path(rooms));
    while (rooms->links[i] && !rooms->is_end)
    {
        tmp = ft_build_path(existing_paths, rooms->links[i]);
        if (ft_path_len(tmp) < min_path && ft_is_free(existing_paths, tmp))
        {
            free(result);
            result = tmp;
            min_path = ft_path_len(tmp);
        }
        else
            free(tmp);
        i++;
    }
    tmp = ft_create_path(rooms);
    tmp->next = result;
    result = tmp;
    return (result);
}