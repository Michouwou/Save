/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 16:39:02 by mlevieux         ###   ########.fr       */
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

	open = opendir("./");
	data = ft_create_data();
	stat = (struct stat*)malloc(sizeof(struct stat));
	if ((dir = readdir(open)) != NULL)
	{
		lstat("./a.out", stat);
		if (stat->st_mode & S_IRWXU)
		printf("ca marche wesh\n");
		ft_get_whole_data(dir, &data);
		data->name = dir->d_name;
		printf("name : %s\n", data->name);
		printf("mode : %s\n", data->mode);
		printf("type : %c\n", data->type);
		printf("mont : %s\n", data->date_mon);
		printf("numb : %s\n", data->date_num);
		printf("hour : %s\n", data->date_hour);
		printf("time : %lld\n", data->time);
		printf("size : %ld\n", data->size);
		printf("grpn : %s\n", data->group_name);
		printf("user : %s\n", data->user_name);
		printf("lnks : %d\n", data->links);
	}
	return (0);
}
