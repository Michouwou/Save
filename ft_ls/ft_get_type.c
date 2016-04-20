/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 14:59:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    ft_get_type(mode_t mode)
{
	mode = mode & S_IFMT;
	if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISLNK(mode))
		return ('l');    
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}
