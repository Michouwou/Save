/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:53:36 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/16 09:37:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		ft_find_square_len(t_superform *super)
{
	int		x_max;
	int		y_max;
	t_point	*list;

	x_max = 0;
	y_max = 0;
	list = super->points;
	while ((*list).id_form != -1)
	{
		x_max = ft_max(x_max, (*list).x);
		y_max = ft_max(y_max, (*list).y);
		list++;
	}
	return (ft_max(x_max, y_max) + 1);
}

int		ft_grade_format(t_superform *to_grade)
{
	int		grade;
	int		x;
	int		y;
	t_point *tmp;

	grade = 1;
	tmp = to_grade->points;
	while (tmp->id_form != -1)
	{
		x = tmp->x;
		y = tmp->y;
		grade += (x + y) + tmp->id_form;
		tmp++;
	}
	return (grade);
}
