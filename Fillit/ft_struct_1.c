/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_struct_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:04:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 12:31:52 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

t_point		*ft_new_point(int x, int y, int id)
{
	t_point	*new_point;

	new_point = (t_point*)malloc(sizeof(t_point));
	if (new_point != NULL)
	{
		new_point->x = x;
		new_point->y = y;
		new_point->id_form = id;
	}
	return (new_point);
}

t_form		*ft_new_form(int id_form)
{
	t_form *new_form;

	new_form = (t_form*)malloc(sizeof(t_form));
	new_form->origin = ft_new_point(0, 0, id_form);
	new_form->p2 = ft_new_point(0, 0, id_form);
	new_form->p3 = ft_new_point(0, 0, id_form);
	new_form->p4 = ft_new_point(0, 0, id_form);
	new_form->id_form = id_form;
	return (new_form);
}

void		ft_form_add_point(t_form *form, t_point *point)
{
	if (form != NULL && point != NULL)
	{
		if (form->origin->x != 0)
			form->origin = ft_new_point(0, 0, form->id_form);
		if (form->p2->x == 0 && form->p2->y == 0)
		{
			form->p2 = point;
			form->p2->id_form = form->id_form;
		}
		else if (form->p3->x == 0 && form->p3->y == 0)
		{
			form->p3 = point;
			form->p3->id_form = form->id_form;
		}
		else if (form->p4->x == 0 && form->p4->y == 0)
		{
			form->p4 = point;
			form->p4->id_form = form->id_form;
		}
		else
			ft_error();
	}
}

t_point		*ft_point_sum(t_point *point1, t_point *point2)
{
	int		x_sum;
	int		y_sum;
	int		id;
	t_point	*point_sum;

	if (point1 != NULL && point2 != NULL)
	{
		x_sum = point1->x + point2->x;
		y_sum = point1->y + point2->y;
		id = point1->id_form;
		point_sum = ft_new_point(x_sum, y_sum, id);
		return (point_sum);
	}
	else
		return (NULL);
}

t_superform	*ft_new_superform(void)
{
	t_superform **new;
	int			id;

	new = (t_superform**)malloc(sizeof(t_superform*) * 1);
	*new = (t_superform*)malloc(sizeof(t_superform) * 1);
	if (*new != NULL)
	{
		id = -1;
		(*new)->points = (t_point*)malloc(sizeof(t_point) * 104);
		(*new)->points[0] = *ft_new_point(0, 0, id);
		return (*new);
	}
	else
		return (NULL);
}
