/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_forms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:09:31 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 12:37:04 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libfillit.h"

static void		ft_f_in(int tab[6], t_superform *tot, t_form *tmp, t_point *p)
{
	char	*char_tmp;

	char_tmp = (char*)malloc(sizeof(char) * 600);
	while (++tab[2] < 5 && tab[1] > 0)
	{
		tab[1] = read(tab[5], char_tmp, 1);
		if (tab[1] == 0 && tot->points[0].id_form == -1)
		{
			printf("ERROR\n");
			ft_error();
		}
		if (tab[1] <= 0)
			break ;
		if (*char_tmp == '#' && tab[4] != -1)
		{
			p = ft_new_point(tab[2] - (tab[4] / 10),
					tab[3] - (tab[4] % 10), tab[0]);
			ft_form_add_point(tmp, p);
		}
		if (*char_tmp == '#' && tab[4] == -1)
			tab[4] = tab[2] * 10 + tab[3];
	}
}

static void		ft_declare_tab(int values[6], t_superform **tot, char **f_name)
{
	values[4] = -1;
	values[0] = 1;
	*tot = ft_new_superform();
	values[1] = 1;
	values[5] = open(*f_name, O_RDONLY, S_IRUSR | S_IWUSR);
}

static void		ft_test(int values[6], t_superform **total, t_form **tmp)
{
	values[4] = -1;
	if (!ft_form_is_valid(*tmp))
	{
		printf("ERROR\n");
		ft_error();
	}
	printf("Wowowo --> %d\n", (*tmp)->id_form);
	ft_add_first_form(*total, *tmp);
	free(*tmp);
}

t_superform		*ft_get_forms(char *file_name, char **char_tmp)
{
	t_superform *total;
	t_form		*tmp;
	t_point		*point_tmp;
	int			values[6];

	point_tmp = NULL;
	ft_declare_tab(values, &total, &file_name);
	while (values[1] > 0)
	{
		tmp = ft_new_form(values[0]);
		printf("New form\n");
		values[3] = -1;
		while (++values[3] < 4 && values[1] > 0)
		{
			values[2] = -1;
			ft_f_in(values, total, tmp, point_tmp);
		}
		values[1] = read(values[5], *char_tmp, 1);
		values[0]++;
		ft_test(values, &total, &tmp);
	}
	close(values[5]);
	return (total);
}

int				ft_count_forms(t_superform **total)
{
	int i;
	int j;
	int *stock_id;

	i = 0;
	stock_id = (int*)malloc(sizeof(int) * 27);
	while (i < 27)
		stock_id[i++] = 0;
	i = 0;
	j = 0;
	printf("%d AAHHHHHHHH\n", (*total)->points[i].id_form);
	while ((*total)->points[i].id_form != -1)
	{
		j = 0;
		while (stock_id[j] != 0 && stock_id[j] != (*total)->points[i].id_form)
		{
			printf("%d\n", stock_id[j]);
			j++;
		}
		stock_id[j] = (*total)->points[i].id_form;
		i++;
	}
	while (stock_id[j] != 0)
		j++;
	printf("%d, jjjjjjjj\n", j);
	return (j + 1);
}
