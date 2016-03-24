/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 21:02:27 by mlevieux         ###   ########.fr       */
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
#include "libft.h"

typedef struct	s_data
{
	char			*name;
	char			*mode;
	char			type;
	char			*date_mon;
	char			*date_num;
	char			*date_hour;
	long long		time;
	long			size;
	char			*group_name;
	char			*user_name;
	int				links;
	int				is_dir;
	char			*path;
	struct s_data	**next;
}				t_data;

void			ft_parse_date(time_t time, t_data **data);
char			*ft_parse(char **argv, char ***file_names);
void			ft_print_list(t_data *data);
t_data			*ft_create_data(void);
void			ft_get_whole_data(struct dirent *dir, t_data **data);
void			ft_get_mode(mode_t st_mode, t_data **data);
int				ft_isdir(mode_t st_mode);
int				ft_max_width(t_data **datas, int flag);

