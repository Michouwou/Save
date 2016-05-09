/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:02:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 14:51:09 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_display(char *sols, char *options, t_stack *first)
{
	int		len;
	int		ret;
	int		num;
	t_stack	*tmp;

	num = -1;
	ret = 0;
	len = 0;
	tmp = first;
	while (sols[++num])
		if (sols[num] == ' ')
			len++;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;;
	}
	if (options[2])
	{
		write(1, "\033[0;33m", 7);
		ft_putnbr(len);
		write(1, " operations pour ", 17);
		ft_putnbr(ret);
		write(1, " entrees\n", 9);
		write(1, "\033[0;m", 5);
	}
	num = ft_strlen(sols) - 1;
	write(1, sols + 1, num);
	return ((int)(len / ret));
}
