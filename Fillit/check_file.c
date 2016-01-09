/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:41:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/04 09:52:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int				ft_check_format(char *t, char *file_name)
{
	int		i;
	int		j;
	int		k;
	int		fd;

	i = 1;
	fd = open(file_name, O_RDONLY, S_IWUSR | S_IRUSR);
	while (i > 0)
	{
		k = -1;
		while (++k < 4 && i > 0)
		{
			if (read(fd, t, 1) <= 0)
				return (1);
			j = 0;
			while (++j < 5 && i > 0 && *t != '\n')
				i = read(fd, t, 1);
			if (*t != '\n' || (j != 5 && j != 0))
				return (0);
		}
		if (k != 4 || *t != '\n' || read(fd, t, 1) <= 0)
			return (0);
	}
	close(fd);
	return (1);
}

int				ft_check_filling(char *t, char *file_name)
{
	int i;
	int fd;

	fd = open(file_name, O_RDONLY, S_IWUSR | S_IRUSR);
	if (fd == -1)
		ft_error();
	i = 1;
	while (i > 0)
	{
		i = read(fd, t, 1);
		if (*t != '.' && *t != '#' && *t != '\n')
			return (0);
	}
	close(fd);
	return (1);
}

int				ft_launch_check(char *file_name)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * 32000);
	if (ft_check_format(buf, file_name) && ft_check_filling(buf, file_name))
		return (1);
	return (0);
}

static void		ft_exception(t_form *form)
{
	t_point *p2;
	t_point *p3;
	t_point *p4;

	p2 = form->p2;
	p3 = form->p3;
	p4 = form->p4;
	if (p2->x == 1 && p2->y == 0)
		if (p3->x == 0 && p3->y == 2)
			if (p4->x == 1 && p4->y == 2)
				ft_error();
	if (p2->x == 2 && p2->y == 0)
		if (p3->x == 0 && p3->y == 1)
			if (p4->x == 2 && p4->y == 1)
				ft_error();
}

int				ft_form_is_valid(t_form *form)
{
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;

	ft_exception(form);
	xmax = ft_max(form->p2->x, ft_max(form->p3->x, form->p4->x));
	xmin = ft_min(form->p2->x, ft_min(form->p3->x, form->p4->x));
	ymax = ft_max(form->p2->y, ft_max(form->p3->y, form->p4->y));
	ymin = ft_min(form->p2->y, ft_min(form->p3->y, form->p4->y));
	if ((xmax - xmin) + (ymax - ymin) <= 3)
		return (1);
	return (0);
}
