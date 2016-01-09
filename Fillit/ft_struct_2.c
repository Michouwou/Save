/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_struct_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:56:34 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 15:33:55 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

size_t	ft_listlen(t_point *list)
{
	size_t	result;

	result = 0;
	while (list->id_form != -1)
	{
		result++;
		list++;
	}
	return (result);
}

void	ft_add_form(t_superform *superform, t_form *form, t_point *origin)
{
	int len;
	int last_id;

	if (superform != NULL && form != NULL && origin != NULL)
	{
		last_id = -1;
		len = ft_listlen(superform->points);
		superform->points[len] = *ft_point_sum(form->origin, origin);
		superform->points[len + 1] = *ft_point_sum(form->p2, origin);
		superform->points[len + 2] = *ft_point_sum(form->p3, origin);
		superform->points[len + 3] = *ft_point_sum(form->p4, origin);
		superform->points[len + 4] = *ft_new_point(0, 0, last_id);
	}
}

void	ft_add_first_form(t_superform *super, t_form *to_add)
{
	int		len;
	int		last_id;
	t_point	*nul_point;

	last_id = -1;
	if ((to_add->p2->x == 0 && to_add->p2->y == 0) || (to_add->p3->x == 0
			&& to_add->p3->y == 0) || (to_add->p4->x == 0 &&
				to_add->p4->y == 0))
		ft_error();
	if (super != NULL && to_add != NULL)
	{
		nul_point = ft_new_point(0, 0, to_add->id_form);
		len = ft_listlen(super->points);
		super->points[len] = *ft_point_sum(to_add->origin, nul_point);
		super->points[len + 1] = *ft_point_sum(to_add->p2, nul_point);
		super->points[len + 2] = *ft_point_sum(to_add->p3, nul_point);
		super->points[len + 3] = *ft_point_sum(to_add->p4, nul_point);
		super->points[len + 4] = *ft_new_point(0, 0, last_id);
	}
}

int		ft_match(t_superform *prev, t_form *form, t_point *origin, int min_tab)
{
	t_point *p2;
	t_point *p3;
	t_point *p4;

	p2 = form->p2;
	p3 = form->p3;
	p4 = form->p4;
	if (p2->x + origin->x > -1 && p2->x + origin->x < min_tab &&
			p2->y + origin->y > -1 && p2->y + origin->y < min_tab &&
			p3->x + origin->x > -1 && p3->x + origin->x < min_tab &&
			p3->y + origin->y > -1 && p3->y + origin->y < min_tab &&
			p4->x + origin->x > -1 && p4->x + origin->x < min_tab &&
			p4->y + origin->y > -1 && p4->y + origin->y < min_tab)
		if (ft_isempty(prev, p2->x + origin->x, p2->y + origin->y))
			if (ft_isempty(prev, p3->x + origin->x, p3->y + origin->y))
				if (ft_isempty(prev, p4->x + origin->x, p4->y + origin->y))
					return (1);
	return (0);
}
