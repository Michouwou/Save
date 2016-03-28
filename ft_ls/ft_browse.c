/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:40:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_browse(t_data **data, char *entry_dir, int flag)
{
	int				i;
	int				j;
	DIR				*directory;
	struct dirent	*dir;
	struct stat		*stat;

	i = -1;
	stat = (struct stat*)malloc(sizeof(struct stat));
	(*data)->next = (t_data**)malloc(sizeof(t_data*) * 100);
	while (++i < 100)
		(*data)->next[i] = NULL;
	i = 0;
	directory = opendir(entry_dir);
	while ((dir = readdir(directory)) != NULL)
	{
		(*data)->next[i] = ft_create_data();
		(*data)->next[i]->name = ft_strdup(dir->d_name);
		ft_get_whole_data(dir, &((*data)->next[i]));
		ft_get_path(data, (*data)->next[i]);
		if (flag == 1 && (*data)->next[i]->is_dir)
			ft_browse(&((*data)->next[i]), (*data)->next[i]->path, 1); 
		i++;
	}
	closedir(directory);
	free(stat);
}
