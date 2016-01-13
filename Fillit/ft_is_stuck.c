/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_stuck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:07:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/13 10:29:57 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		ft_is_stuck(t_form *f, t_point *pt)
{
	int connect;

	connect = 0;
	if ((pt->x == f->origin->x && (pt->y == f->origin->y + 1 ||
				pt->y == f->origin->y - 1)) || (pt->y == f->origin->y &&
				(pt->x == f->origin->x + 1 || pt->x == f->origin->x - 1)))
		connect++;
	if ((pt->x == f->p2->x && (pt->y == f->p2->y + 1 || pt->y == f->p2->y - 1))
				|| (pt->y == f->p2->y && (pt->x == f->p2->x + 1
				|| pt->x == f->p2->x - 1)))
		connect++;
	if ((pt->x == f->p3->x && (pt->y == f->p3->y + 1 ||
				pt->y == f->p3->y - 1)) || (pt->y == f->p3->y &&
				(pt->x == f->p3->x + 1 || pt->x == f->p3->x - 1)))
		connect++;
	if ((pt->x == f->p4->x && (pt->y == f->p4->y + 1 ||
				pt->y == f->p4->y - 1)) || (pt->y == f->p4->y &&
				(pt->x == f->p4->x + 1 || pt->x == f->p4->x - 1)))
		connect++;
	return (connect);
}
