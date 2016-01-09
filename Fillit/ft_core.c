/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:28:48 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/17 11:34:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

t_superform		*ft_core(t_superform *total)
{
	int			min_tab;
	int			calculus_state;
	t_superform	*result;

	min_tab = ft_min_tab(ft_count_forms(&total));
	result = ft_new_superform();
	calculus_state = ft_resolve(total, min_tab, result, 0);
	while (calculus_state != 1)
	{
		ft_erase_form(result, 0);
		min_tab++;
		calculus_state = ft_resolve(total, min_tab, result, 0);
	}
	return (result);
}
