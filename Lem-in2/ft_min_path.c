/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:12:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/11 15:15:08 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_min_path(t_path *path_one, t_path *path_two)
{
	int		lena;
	int		lenb;

	lena = ft_path_len(path_one);
	lenb = ft_path_len(path_two);
	return (lena > lenb ? lenb : lena);
}
