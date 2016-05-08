/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:02:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 16:36:21 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display(char *sols, char *options)
{
	int		len;
	int		num;

	num = -1;
	len = 0;
	while (sols[++num])
		if (sols[num] == ' ')
			len++;
	ft_putnbr(len);
	write(1, "\n", 1);
	len = ft_strlen(sols) - 1;
	write(1, sols + 1, len);
}
