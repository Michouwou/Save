/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 20:16:19 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/22 15:42:48 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_is_memory(t_memory *memory, int const fd)
{
	t_memory	*tmp;
	char		*ret;

	tmp = memory;
	ret = NULL;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			ret = (*tmp->next_lines);
		tmp = tmp->next;
	}
	return (ret);
}

int		ft_set_memory(int const fd, t_memory **memory)
{
	t_memory	*tmp;
	t_memory	*tmpb;

	tmp = *memory;
	while (tmp != NULL)
	{
		tmpb = tmp;
		tmp = tmp->next;
	}
	tmp = (t_memory*)malloc(sizeof(t_memory) * 1);
	tmp->next = NULL;
	if (tmpb)
		tmpb->next = tmp;
	if (*memory == NULL)
		*memory = tmp;
	tmp->fd = fd;
	tmp->next = NULL;
	tmp->next_lines = (char**)malloc(sizeof(char*));
	(*tmp->next_lines) = ft_strnew((BUFF_SIZE) + 1);
	if (ft_next_read(fd, tmp->next_lines) == -1)
		return (-1);
	return (1);
}

int		ft_next_line(char *rest, char **line, int fd, t_memory *memory)
{
	t_memory	*tmpm;

	tmpm = memory;
	while (tmpm->fd != fd)
		tmpm = tmpm->next;
	fd = 0;
	while (rest[fd] != '\n' && rest[fd] != '\0' && rest[fd] != 3)
		fd++;
	if (rest[fd] == '\0')
	{
		if (ft_next_read(tmpm->fd, &rest) == -1)
			return (-1);
		return (ft_next_line(rest, line, tmpm->fd, memory));
	}
	if (rest[fd] == 3 && fd == 0)
	{
		rest[fd] = '\n';
		if (ft_next_line(rest, line, tmpm->fd, memory) != -1)
			return (0);
		return (-1);
	}
	*line = ft_strsub(rest, 0, fd);
	*tmpm->next_lines = ft_strsub(rest, fd + 1, ft_strlen(rest));
	free(rest);
	return (1);
}

int		ft_next_read(int const fd, char **rest)
{
	int		i;
	int		status;
	char	*tmp;

	i = ft_strlen(*rest);
	tmp = *rest;
	*rest = ft_strnew(i + BUFF_SIZE + 1);
	ft_strcpy(*rest, tmp);
	free(tmp);
	status = read(fd, (*rest) + i, BUFF_SIZE);
	if (status == -1)
		return (-1);
	if (status == 0)
	{
		(*rest)[ft_strlen(*rest)] = 3;
		return (0);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_memory	*memory;
	char			*rest;

	if (!line)
		return (-1);
	rest = ft_is_memory(memory, fd);
	if (rest != NULL)
		return (ft_next_line(rest, line, fd, memory));
	else
	{
		if (ft_set_memory(fd, &memory) == -1)
			return (-1);
		return (get_next_line(fd, line));
	}
}
