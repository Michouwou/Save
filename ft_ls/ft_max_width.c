/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:28:35 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 02:21:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_max_width(t_data **datas, int flag)
{
	int max;
	int i;

	max = 0;
	i = 0;
	while (datas[i])
	{
		if (flag == 1)
			max = ft_max(ft_strlen(ft_itoa(datas[i]->links)), max);
		printf("1");
		fflush(stdout);
		if (flag == 2)
			max = ft_max(ft_strlen(datas[i]->user_name), max);
		printf("2");
		fflush(stdout);
		if (flag == 3)
			max = ft_max(ft_strlen(datas[i]->group_name), max);
		printf("3");
		fflush(stdout);
		if (flag == 4)
			max = ft_max(ft_strlen(ft_itoa(datas[i]->size)), max);
		printf("4");
		fflush(stdout);
		if (flag == 5)
			max = ft_max(ft_strlen(datas[i]->date_num), max);
		printf("5");
		fflush(stdout);
		if (flag == 6)
			max = ft_max(ft_strlen(datas[i]->name), max);
		printf("6");
		fflush(stdout);
		i++;
	}
	return (max);
}
