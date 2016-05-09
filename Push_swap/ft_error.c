/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:57:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/09 11:51:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int code, char *str)
{
	write(1, "\033[0;31m", 7);
	if (code == 0)
	{
		write(1, "Error : invalid option \"", 24);
		write(1, str, 1);
		write(1, "\"\n", 2);
	}
	else if (code == 1)
	{
		write(1, "Error : invalid argument \"", 26);
		write(1, str, ft_strlen(str));
		write(1, "\"\n", 2);
	}
	else if (code == 2)
	{
		write(1, "Argument \"", 10);
		write(1, str, ft_strlen(str));
		write(1, "\" appears twice but option 'd' is not specified\n", 47);
	}
	write(1, "\033[0;m", 5);
	exit(0);
}
