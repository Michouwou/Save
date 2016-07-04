/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:57:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/11 17:10:45 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	code_two_three(int code, char *str)
{
	if (code == 2)
	{
		write(1, "Error : argument \"", 17);
		write(1, str, ft_strlen(str));
		write(1, "\" appears twice but option 'd' is not specified\n", 47);
	}
	else if (code == 3)
	{
		write(1, "Error : \"", 9);
		write(1, str, ft_strlen(str));
		write(1, "\" is not representable as an int\n", 34);
	}
}

void		ft_error(int code, char *str)
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
	else
		code_two_three(code, str);
	write(1, "\033[0;m", 5);
	exit(0);
}
