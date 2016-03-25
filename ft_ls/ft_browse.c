/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 01:09:48 by mlevieux         ###   ########.fr       */
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
	(*data)->next = (t_data**)malloc(sizeof(t_data*) * 100);
	directory = opendir(entry_dir);
	while ((dir = readdir(directory)) != NULL)
	{
		(*data)->next[i] = ft_create_data();
		printf("Dir->d_name : %s\n", dir->d_name);
		(*data)->next[i]->name = ft_strdup(dir->d_name);
		ft_get_whole_data(dir, data);
		ft_get_path(data, (*data)->next[i]);
		if (flag == 1 && (*data)->next[i]->is_dir)
			ft_browse(&((*data)->next[i]), (*data)->next[i]->path, 1); 
		i++;
	}
	closedir(directory);
	free(stat);
}
