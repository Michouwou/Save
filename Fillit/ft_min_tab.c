/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:29:20 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/15 22:29:14 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int		ft_min_tab(int nb_forms)
{
	int	i;

	i = 0;
	nb_forms *= 4;
	while (i * i < nb_forms)
		i++;
	return (i);
}