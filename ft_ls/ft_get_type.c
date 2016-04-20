/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 12:38:43 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    ft_get_type(mode_t mode)
{
	char c;

	/*	mode = mode & S_IFMT;
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
		*/
	switch (mode & S_IFMT) {
		case S_IFBLK:  c = 'b';      break;
		case S_IFCHR:  c = 'c'; break;
		case S_IFDIR:  c = 'd';                break;
		case S_IFIFO:  c = 'p';                 break;
		case S_IFLNK:  c = 'l';           break;
		case S_IFREG:  c = '-';         break;
		case S_IFSOCK: c = 's';                    break;
		default:       printf("inconnu ?\n");                 break;
	}
	return (c);
}
