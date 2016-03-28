/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_rep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 03:13:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:40:03 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_rep(t_data **rep_content, int time, int rev, int listed)
{
	t_data	*to_display;
	int		i;

	i = 0;
	if (rev)
		to_display = ft_sort_rev(rep_content);
	else if (time)
		to_display = ft_sort_time(rep_content);
	else
		to_display = ft_sort_reg(rep_content);
	if (listed)
		while (to_display[i]->type != -1)
			ft_print_list(to_display, i++);
	else
		ft_print_simple(to_display);
}
