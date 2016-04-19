/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:30:36 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/19 12:14:43 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS

# define _FT_LS
# include <dirent.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include "libft.h"
# include "libftprintf.h"
# define WIN_WIDTH 100

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
	int				permission;
	char			*path;
}				t_data;

typedef struct	s_tree
{
    t_data			*data;
    struct s_tree	*left;
    struct s_tree	*right;
}				t_tree;

void			ft_browse(char *entry_dir, int *flag);
t_data			*ft_create_data(void);
t_tree			*ft_create_node(void);
void			ft_free_tree(t_tree *tree);
void			ft_get_mode(mode_t st_mode, t_data **data);
void			ft_get_path(char *super_path, t_data *sub_data);
char			ft_get_type(mode_t mode);
void			ft_get_whole_data(struct dirent *dir, t_data **data);
int				*ft_get_widths(t_tree *tree, int *tab);
void			ft_insert_sort(t_data *data, t_tree **first, int flag);
int				ft_isdir(mode_t st_mode);
void			ft_median_browse(t_tree *tree, int *flag);
int				*ft_parse(char **argv, char ***file_names);
void			ft_parse_date(time_t time, t_data **data);
void			ft_print_list(t_tree *node, int *index); // A revoir
void			ft_print_tree(t_tree *tree, int *flag, int *widths);
void			ft_simple_print(t_tree *tree, int *widths);

#endif
