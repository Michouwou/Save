/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:12:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/25 15:57:32 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_path(t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (path)
	{
		path = path->next;
		free(tmp);
		tmp = path;
	}
}

t_path	*ft_min_path(t_path *path_one, t_path *path_two)
{
	int		lena;
	int		lenb;

	lena = ft_path_len(path_one);
	lenb = ft_path_len(path_two);
	if (!lena && !lenb)
		return (NULL);
	if (!lena || !lenb)
		return ((!lena) ? path_two : path_one);
	if (lena > lenb)
	{
		ft_free_path(path_one);
		return (path_two);
	}
	else
	{
		ft_free_path(path_two);
		return (path_one);
	}
}
