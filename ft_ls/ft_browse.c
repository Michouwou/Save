/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:02:42 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/19 14:36:09 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * flag contiendra l'option -t a l'indice 1, l'option -l a l'indice 2, l'option
 * -r a l'indice 3, l'option -R a l'indice 0, et l'option -a a l'indice 4
**/

static int	*int_tab(void)
{
	int	*tab;
	int	i;
	
	i = 0;
	tab = (int*)malloc(sizeof(int) * 7);
	while (i < 7)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void		ft_browse(char *entry_dir, int *flag)
{
	DIR				*directory;
	struct dirent	*dir;
	t_tree			**tree;
	t_data			*element;

	int i =0;
	directory = opendir(entry_dir);
	tree = (t_tree**)malloc(sizeof(t_tree*));
	*tree = NULL;
	while ((dir = readdir(directory)) != NULL)
	{
		if (!(dir->d_name[0] == '.' && !flag[4]))
		{
			element = ft_create_data();
			element->name = ft_strdup(dir->d_name);
			ft_get_path(entry_dir, element);
			ft_get_whole_data(dir, &element);
			ft_insert_sort(element, tree, flag[1]);
			i++;
		}
	}
	if (*tree)
	{
		ft_print_tree(*tree, flag, ft_get_widths(*tree, int_tab()));
		ft_median_browse(*tree, flag);
		write(1, "oui\n", 4);
		ft_free_tree(*tree);
	}
	closedir(directory);
	free(dir);
	printf("%d\n", i);
}
