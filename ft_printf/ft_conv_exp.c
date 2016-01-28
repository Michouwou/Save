/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:12:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/28 15:19:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_find_accuracy(long double number, int accuracy)
{
	int ret;

	ret = 0;
	printf("ENTERING\n");
	NOW
	if (accuracy < 0)
		accuracy = 6;
	while (ft_strlen(ft_itoa((int)(number))) <= accuracy)
	{
		number *= 10.0;
		ret++;
		printf("Modulo - num = %Lf!\n", number);
		NOW
	}
	printf("%d, ret\n", ret);
	NOW
	return (ret);
}

char	*ft_conv_exp(char *buff, long double number, T_LIST *trail)
{
	int		i;
	int		j;
	int		k;
	int		is_zero;
	char	*result;

	printf("%d\n Yoyoyoyoy\n", trail->accuracy);
	buff = ft_conv_float(number, ft_find_accuracy(number, trail->accuracy));
	i = 0;
	k = 0;
	result = ft_strnew(ft_strlen(buff) + 1);
	while (buff[i] != '.' && buff[i] != 0)
		i++;
	printf("1111111\n");
	NOW
	if (buff[i] == 0)
		return (buff);
	j = i + 1;
	while (buff[j] == '0' && buff[j] != 0)
		j++;
	printf("2222222\n");
	NOW
	if (buff[j] != 0)
		i = (j > i + 1) ? i - j : i - 1;
	j = 0;
	while (buff[j] != 0)
	{
		while (k == 0 && (buff[j] == '0' || buff[j] == '.'))
			j++;
		if (k == 1)
			result[k++] = '.';
		if (buff[j] == '.')
			j++;
		result[k++] = buff[j++];
	}
	printf("333333\n");
	NOW
	result = ft_repstr(result, k, k, (i >= 0 && !(i == 0 && buff[i] == '0')) ? "e+" : "e");
	k = ft_strlen(result);
	result = ft_repstr(result, k, k, ft_itoa((buff[i] == '0' && i == 0) ?
				i = -1 : i));
	if (i < 10)
		result = ft_repstr(result, (i < 0) ? k = k + 1 : k, k, "0");
	return (result);
}
