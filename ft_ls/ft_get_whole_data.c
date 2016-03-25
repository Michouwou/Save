/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_whole_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:46:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/25 02:14:26 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_whole_data(struct dirent *dir, t_data **data)
{
	struct stat		*stat;
	struct group	*grp;
	struct passwd	*pwd;

	stat = (struct stat*)malloc(sizeof(struct stat));
	if (!lstat((*data)->name, stat))
	{
		grp = getgrgid(stat->st_gid);
		pwd = getpwuid(stat->st_uid);
		ft_get_mode(stat->st_mode, data);
		printf("Mode : %s\n", (*data)->mode);
		ft_parse_date(stat->st_mtime, data);
		printf("Date : %s/%s/%s\n", (*data)->date_mon, (*data)->date_num, (*data)->date_hour);
		(*data)->time = stat->st_mtime;
		printf("Time : %lld\n", (*data)->time);
		(*data)->size = stat->st_size;
		printf("Size : %ld\n", (*data)->size);
		(*data)->group_name = ft_strdup(grp->gr_name);
		printf("Group : %s\n", (*data)->group_name);
		(*data)->user_name = ft_strdup(pwd->pw_name);
		printf("User : %s\n", (*data)->user_name);
		(*data)->links = stat->st_nlink;
		printf("Links : %d\n", (*data)->links);
		(*data)->is_dir = ft_isdir(stat->st_mode);
		printf("Dir? : %d\n", (*data)->is_dir);
	}
}
