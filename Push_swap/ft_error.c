/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:57:20 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/08 14:00:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int code)
{
	if (code == 0)
		write(1, "Error : invalid option\n", 23);
	else if (code == 1)
		write(1, "Error : invalid argument\n", 25);
	exit(0);
}
