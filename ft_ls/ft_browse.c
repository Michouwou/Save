/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 22:03:58 by mlevieux         ###   ########.fr       */
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

	i = 0;
	stat = (struct stat*)malloc(sizeof(struct stat));
	(*data)->next = (t_data**)malloc(sizeof(t_data*) * (*data)->links);
	directory = opendir(entry_dir);
	while (i < (*data)->links)
	{
		dir = readdir(directory);
		(*data)->next[i] = ft_create_data();
		(*data)->next[i]->name = dir->d_name;
		ft_get_path(data, (*data)->next[j]);
		ft_get_whole_data(dir, data);
		if (flag == 1 && (*data)->next[j]->is_dir)
			ft_browse(&((*data)->next[j]), (*data)->next[j]->path, 1); 
		i++;
	}
}
