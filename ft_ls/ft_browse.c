/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 12:09:53 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * flag contiendra l'option -t a l'indice 1, l'option -l a l'indice 2, l'option
 * -r a l'indice 3, l'option -R a l'indice 0, et l'option -a a l'indice 4
 **/

void		ft_browse(char *entry_dir, int *flag)
{
	DIR				*directory;
	struct dirent	*dir;
	t_tree			*tree;
	t_data			*element;

	directory = opendir(entry_dir);
	//tree = (t_tree**)malloc(sizeof(t_tree*));
	tree = NULL;
	write(1, "a", 1);
	while ((dir = readdir(directory)) != NULL)
	{
		if (!(dir->d_name[0] == '.' && !flag[4]))
		{
			element = ft_create_data();
			write(1, "b", 1);
			element->name = ft_strdup(dir->d_name);
			write(1, "c", 1);
			ft_get_path(entry_dir, element);
			write(1, "d", 1);
			ft_get_whole_data(dir, &element);
			write(1, "e", 1);
			ft_insert_sort(element, &tree, flag[1]);
			write(1, "f", 1);
		}
	}
	write(1, "g", 1);
	if (tree)
	{
		write(1, "g2", 2);
		ft_print_tree(tree, flag, ft_get_widths(tree, NULL));
		write(1, "h", 1);
		ft_median_browse(tree, flag);
		write(1, "i", 1);
		ft_free_tree(tree);
		write(1, "j", 1);
	}
	closedir(directory);
	free(dir);
}
