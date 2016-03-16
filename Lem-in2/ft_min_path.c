/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:12:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/16 11:22:07 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_min_path(t_path *path_one, t_path *path_two)
{
	int		lena;
	int		lenb;

	printf("In min_path\n");
	lena = ft_path_len(path_one);
	lenb = ft_path_len(path_two);
	printf("After path_len\n");
	fflush(stdout);
	if (lena > lenb)
	{
		free(path_one);
		printf("Out\n");
		fflush(stdout);
		return (path_two);
	}
	else
	{
		free(path_two);
		printf("Out\n");
		fflush(stdout);
		return (path_one);
	}
}
