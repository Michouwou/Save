/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:41:33 by mlevieux          #+#    #+#             */
/*   Updated: 2016/01/27 15:01:37 by mlevieux         ###   ########.fr       */
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
			if (read(fd, t, 1) == 0)
				return (0);
			j = 0;
			while (++j < 5 && i > 0 && *t != '\n')
				i = read(fd, t, 1);
			if (*t != '\n' || (j != 5 && j != 0))
				return (0);
		}
		if (k != 4 || *t != '\n')
			return (0);
		i = read(fd, t, 1);
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

	buf = (char*)malloc(sizeof(char) * 3200);
	if (ft_check_format(buf, file_name) && ft_check_filling(buf, file_name))
		return (1);
	return (0);
}

int				ft_form_is_valid(t_form *form)
{
	if ((ft_is_stuck(form, form->origin) + ft_is_stuck(form, form->p2) +
			ft_is_stuck(form, form->p3) + ft_is_stuck(form, form->p4)) >= 5)
		return (1);
	return (0);
}
