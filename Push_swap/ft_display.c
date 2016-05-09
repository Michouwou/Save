/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:02:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 11:41:51 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display(char *sols, char *options, t_stack *first)
{
	int		len;
	int		num;
	t_stack	*tmp;

	num = -1;
	if (options[2])
	{
		write(1, "\033[0;33m", 7);
		len = 0;
		tmp = first;
		while (sols[++num])
			if (sols[num] == ' ')
				len++;
		ft_putnbr(len);
		len = 0;
		while (tmp)
		{
			tmp = tmp->next;
			len++;
		}
		write(1, " operations pour ", 17);
		ft_putnbr(len);
		write(1, " entrees\n", 9);
		write(1, "\033[0;m", 5);
	}
	len = ft_strlen(sols) - 1;
	write(1, sols + 1, len);
}
