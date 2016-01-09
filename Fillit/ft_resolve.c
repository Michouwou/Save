/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:39:09 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 11:44:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

static void	ft_in(int t[3], t_superform *r, t_superform *tot, int *tab)
{
	ft_add_form(r, ft_convert(tot, tot->points[t[3]].id_form),
			ft_new_point(t[1], t[0], 0));
	t[3] += 4;
	t[2] = ft_resolve(tot, *tab, r, t[3]);
	if (t[2] != 1)
	{
		t[3] -= 4;
		ft_erase_form(r, t[3]);
	}
}

int			ft_resolve(t_superform *total, int min, t_superform *res, int form)
{
	int t[4];

	t[3] = form;
	t[0] = -1;
	while (++t[0] < min)
	{
		t[1] = -1;
		while (++t[1] < min)
		{
			if (ft_isempty(res, t[1], t[0]) && ft_match(res, ft_convert(total,
						total->points[form].id_form),
						ft_new_point(t[1], t[0], 0), min))
				ft_in(t, res, total, &min);
			if (ft_count_forms(&res) == ft_count_forms(&total))
				return (1);
		}
	}
	return (-1);
}
