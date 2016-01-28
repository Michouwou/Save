/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 11:12:54 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/28 12:01:41 by mlevieux         ###   ########.fr       */
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
		i = i - j;
	while (buff[j] != 0)
	{
		if (k == 1)
			result[k++] = '.';
		else if (buff[j] == '.')
			j++;
		result[k++] = buff[j++];
	}
	printf("333333\n");
	NOW
	result[k++] = 'e';
	result = ft_repstr(result, k, k, ft_itoa(i));
	return (result);
}
