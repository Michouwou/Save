/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:35:21 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/22 17:26:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_color(char *color, char *to_print)
{
	write(1, "\033[0;", 4);
	write(1, color, ft_strlen(color));
	write(1, "m", 1);
	write(1, to_print, ft_strlen(to_print));
	write(1, "\033[0;m", 5);
}
