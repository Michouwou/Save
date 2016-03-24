/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 16:28:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_get_mode(mode_t mode, t_data **data)
{
    char    *mod;
    
    mod = ft_strdup("---------");
    if (mode & S_IRUSR)
        mod[0] = 'r';
    if (mode & S_IWUSR)
        mod[1] = 'w';
    if (mode & S_IXUSR)
        mod[2] = 'x';
    if (mode & S_IRGRP)
        mod[3] = 'r';
    if (mode & S_IWGRP)
        mod[4] = 'w';
    if (mode & S_IXGRP)
        mod[5] = 'x';
    if (mode & S_IROTH)
        mod[6] = 'r';
    if (mode & S_IWOTH)
        mod[7] = 'w';
    if (mode & S_IXOTH)
        mod[8] = 'x';
    (*data)->mode = mod;
}
