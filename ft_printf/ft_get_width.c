/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:38:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 18:23:00 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_width(char *format, int location)
{
	char	*tmp;
	int		i;
	int		res;

	i = 0;
	location++;
	while ((!ft_isdigit(format[location]) || ft_is_flag(format[location])) &&
				format[location] != '.' && format[location] != '*' &&
				!ft_what_type(format[location]))
		location++;
	if (format[location] == '*')
	{
		printf("YOOO\n");
		return (-10);
	}
	if (format[location] == '.')
		return (0);
	while (ft_isdigit(format[i + location]))
		i++;
	tmp = ft_strnew(i - location + 1);
	tmp = ft_strsub(format, location, i);
	res = (tmp != NULL) ? ft_atoi(tmp) : 0;
	printf("\t\t\tres == %d\n", res);
	NOW
	return (res);
}
