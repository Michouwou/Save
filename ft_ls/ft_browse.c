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

void	ft_browse(char *entry_dir, int *flag)
{
	DIR				*directory;
	struct dirent	*dir;
	struct stat		*stat;
	t_tree			*tree;
	t_data			*element;

	stat = (struct stat*)malloc(sizeof(struct stat));
	directory = opendir(entry_dir);
	tree = NULL;
	while ((dir = readdir(directory)) != NULL)
	{
		element = ft_create_data();
		element->name = dir->d_name;
		ft_get_path(entry_dir, element);
		lstat(element->path, stat);
		ft_get_whole_data(dir, &element);
		ft_insert_sort(element, &tree, flag[1]);
	}
	ft_print_tree(tree, flag);
	ft_median_browse(&tree, flag)
	closedir(directory);
	free(stat);
}
