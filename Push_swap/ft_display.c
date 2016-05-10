/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:02:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/10 17:08:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_color(char *sols)
{
	int	i;

	i = 0;
	while (sols[i])
	{
		if (sols[i] == 'p' && sols[i + 1] == 'a')
		{
			write(1, "\033[0;32m", 7);
			write(1, sols + i, 2);
			i += 2;
			write(1, "\033[0;m", 5);
		}
		else if (sols[i] == 'p' && sols[i + 1] == 'b')
		{
			write(1, "\033[0;33m", 7);
			write(1, sols + i, 2);
			i += 2;
			write(1, "\033[0;m", 5);
		}	
		else if (sols[i] == 'r' && sols[i + 1] == 'a')
		{
			write(1, "\033[0;34m", 7);
			write(1, sols + i, 2);
			i += 2;
			write(1, "\033[0;m", 5);
		}	
		else if (sols[i] == 'r' && sols[i + 1] == 'r' && sols[i + 2] == 'a')
		{
			write(1, "\033[0;35m", 7);
			write(1, sols + i, 3);
			i += 3;
			write(1, "\033[0;m", 5);
		}	
		else if (sols[i] == 's' && sols[i + 1] == 'a')
		{
			write(1, "\033[0;36m", 7);
			write(1, sols + i, 2);
			i += 2;
			write(1, "\033[0;m", 5);
		}
		else
			i++;
		if (sols[i] && i != 1)
			write(1, " ", 1);
	}
}

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
		write(1, "\033[044;33m", 9);
		ft_putnbr(len);
		write(1, " operations pour ", 17);
		ft_putnbr(ret);
		write(1, " entrees", 9);
		write(1, "\033[0m\n", 5);
	}
	if (options[3])
		print_color(sols);
	else
	{
		num = ft_strlen(sols) - (sols[0] == ' ' ? 1 : 0);
		write(1, sols + (sols[0] == ' ' ? 1 : 0), num);
	}
	ft_free(first);
	free(sols);
	return ((int)(len / ret));
}
