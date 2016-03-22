/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:04:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/26 14:25:46 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_display_u(t_sol **sols)
{
	char	**ops;
	char	**colors;
	int		i;
	int		j;

	ops = ft_make_ops();
	colors = ft_make_colors();
	i = 0;
	while (i < (*sols)->len)
	{
		j = 0;
		while (!ft_strcmp(ops[j], *((*sols)->sols)))
			j++;
		ft_color(colors[j], *((*sols)->sols));
		i++;
	}
}

void		ft_display(char *options, t_sol **sols)
{
	int i;

	i = 0;
	if (options[0] == 'c' || options[1] == 'c' ||
			options[2] == 'c' || options[3] == 'c')
	{
		if (options[0] == 'x' || options[1] == 'x' ||
				options[2] == 'x' || options[3] == 'x')
			ft_display_u(sols);
	}
	else
	{
		while (i++ < (*sols)->len - 1)
			ft_printf("%s ", *((*sols)->sols)++);
		if (options[0] == 'c' || options[1] == 'c' ||
			options[2] == 'c' || options[3] == 'c')
			ft_color("36", *((*sols)->sols));
		else
			if ((*sols)->len > 0)
				ft_printf("%s\n", *((*sols)->sols));
	}
}
