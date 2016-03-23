/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_whole_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:46:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 12:58:38 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_whole_data(struct dirent *dir, t_data **data)
{
	struct stat		*stat;
	struct group	*grp;
	struct passwd	*pwd;

	if (!lstat((*data)->path, stat))
	{
		grp = getgrgid(stat->st_gid);
		pwd = getpwuid(stat->st_uid);
		ft_get_mode(stat->st_mod, data);
		ft_parse_date(stat->st_mtime, data);
		(*data)->time = stat->st_mtime;
		(*data)->size = stat->st_size;
		(*data)->group_name = ft_strdup(grp->gr_name);
		(*data)->user_name = ft_strdup(pwd->pw_name);
		(*data)->links = stat->st_nlinks;
		(*data)->is_dir = ft_isdir(stat->st_mode);
	}
}
