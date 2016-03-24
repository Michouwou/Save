/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 18:39:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    ft_get_type(mode_t mode)
{
	char c;

    if (mode & S_IFSOCK)
        c = 's';
    else if (mode & S_IFLNK)
        c = 'l';    
    else if (mode & S_IFREG)
        c = '-';
    else if (mode & S_IFBLK)
        c = 'b';
    else if (mode & S_IFDIR)
        c = 'd';
    else if (mode & S_IFCHR)
        c = 'c';
    else if (mode & S_IFIFO)
        c = 'p';
    return (c);
}
