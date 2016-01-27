/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_accuracy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:46:34 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 18:01:13 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_accuracy(char *format, int location)
{
	int		i;
	int		res;
	char	*tmp;

	i = 0;
	location++;
	while (format[location] != '.' && !ft_what_type(format[location]))
		location++;
	if (ft_what_type(format[location]))
		return (-1);
	i = 1;
	if (format[location + 1] == '*')
		return (-10);
	while (ft_isdigit(format[location + i]))
		i++;
	tmp = ft_strsub(format, location + 1, i);
	res = (tmp != NULL) ? ft_atoi(tmp) : -1;
	return (res);
}
