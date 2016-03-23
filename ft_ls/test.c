/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:33:02 by mlevieux         ###   ########.fr       */
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
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>
#include "ft_ls.h"
#include "libft.h"

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
	if ((dir = readdir(open)) != NULL)
	{
		stat = (struct stat*)malloc(sizeof(struct stat));
		lstat("./", stat);
		grp = getgrgid(stat->st_gid);
		pwd = getpwuid(stat->st_uid);
		printf("%s\n", ctime(&(stat->st_mtime)));
	}
	ft_parse_date(stat->st_mtime, &data);
	printf("%s %s %s\n", data->date_mon, data->date_num, data->date_hour);
	return (0);
}
