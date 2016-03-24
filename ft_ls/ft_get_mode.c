/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:33:02 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *ft_get_mode(mode_t mode)
{
    char    *mode;
    
    mode = ft_strdup("---------");
    if (mode & S_IRUSR)
        mode[0] = 'r';
    if (mode & S_IWUSR)
        mode[1] = 'w';
    if (mode & S_IXUSR)
        mode[2] = 'x';
    if (mode & S_IRGRP)
        mode[3] = 'r';
    if (mode & S_IWGRP)
        mode[4] = 'w';
    if (mode & S_IXGRP)
        mode[5] = 'x';
    if (mode & S_IROTH)
        mode[6] = 'r';
    if (mode & S_IWOTH)
        mode[7] = 'w';
    if (mode & S_IXOTH)
        mode[8] = 'x';
    return (mode);
}