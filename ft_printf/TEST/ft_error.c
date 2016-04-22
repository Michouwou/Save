/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:51:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 16:25:21 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_error(int error_code)
{
	if (error_code == 1)
		write(1, "Wrong format\n", 13);
	if (error_code == 2)
		write(1, "Wrong type/format\n", 18);
	exit(0);
}
