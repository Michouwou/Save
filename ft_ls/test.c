/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/24 19:51:23 by mlevieux         ###   ########.fr       */
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
	t_data **data;


	data = (t_data**)malloc(sizeof(t_data*) * 9);
	data[0] = ft_create_data();
	data[1] = ft_create_data();
	data[2] = ft_create_data();
	data[3] = ft_create_data();
	data[4]= ft_create_data();
	data[5] = ft_create_data();
	data[6] = ft_create_data();
	data[7] = ft_create_data();
	data[8] = ft_create_data();
	
	data[0]->links = 8;
	data[1]->links = 100;
	data[2]->links = 45;
	data[3]->links = 5690;
	data[4]->links = 2;
	data[5]->links = 90;
	data[6]->links = 451;
	data[7]->links = 43;
	data[8]->links = 0;

	data[0]->user_name = ft_strdup("Premier");
	data[1]->user_name = ft_strdup("michel");
	data[2]->user_name = ft_strdup( "mlevieux");
	data[3]->user_name = ft_strdup("lol-lol-lol");
	data[4]->user_name = ft_strdup("de");
	data[5]->user_name = ft_strdup("trois");
	data[6]->user_name = ft_strdup("une chaine!!!");
	data[7]->user_name = ft_strdup("i");
	data[8]->user_name = ft_strdup("oui");
	
	printf("%d\n", ft_max_width(data, 1));
	printf("%d\n", ft_max_width(data, 2));
	return (0);
}
