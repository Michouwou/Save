/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:38:30 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/10 09:43:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     ft_is_free(t_path **existing_paths, t_path *path)
{
    int     i;
    t_path  *tmp;
    t_path  *ex_tmp;
    
    tmp = path;
    while (!tmp->next->node->is_end)
    {
        i = 0;
        while (existing_paths[i])
        {
            ex_tmp = existing_paths[i];
            while (!ex_tmp->next->node->is_end)
            {
                if (!ft_strcmp(ex_tmp->node->name, tmp->node->name))
                    return (0);
                ex_tmp = ex_tmp->next;
            }
            i++;
        }
        tmp = tmp->next;
    }
    return (1);
}

int     ft_path_len(t_path *path)
{
    int     ret;
    t_path  *tmp;
    
    ret = 0;
    tmp = path;
    while (tmp)
    {
        ret++;
        tmp = tmp->next;
    }
    return (ret);
}
