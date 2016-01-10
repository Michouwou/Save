/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:04:52 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/10 12:31:56 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_flag(char c)
{
	if (c == '#' || c == ' ' || c == '0' || c == '+' || c == '-')
		return (1);
	return (0);
}