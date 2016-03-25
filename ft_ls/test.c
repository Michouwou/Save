/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 03:03:36 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"

int main(int argc, char **argv)
{
	struct dirent *dir;
	DIR *open;
	struct stat *stat;
	struct group *grp;
	struct passwd *pwd;
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	open = opendir(".");
	dir = readdir(open);
	while (ft_strcmp(dir->d_name, "."))
		dir = readdir(open);
	data->name = ft_strdup(".");
	data->path = ft_strdup(".");
	ft_browse(&data, data->name, 0);
	for (int i = 0 ; data->next[i] ; i++)
		ft_print_list(data->next, i);
	return (0);
}
