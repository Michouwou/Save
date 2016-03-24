/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 18:53:01 by mlevieux         ###   ########.fr       */
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

	open = opendir(".");
	data = ft_create_data();
	stat = (struct stat*)malloc(sizeof(struct stat));
	while ((dir = readdir(open)) != NULL)
	{
		data->name = dir->d_name;
		ft_get_whole_data(dir, &data);
		printf("%c%s  %d %s  %s  %*ld %s %s %s %s\n", data->is_dir ? 'd' : data->type, data->mode, data->links, data->user_name, data->group_name, ft_strlen(ft_itoa(ft_max(data))), data->size, data->date_mon, data->date_num, data->date_hour, data->name);
	}
	return (0);
}
