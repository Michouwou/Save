/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/23 10:30:51 by mlevieux         ###   ########.fr       */
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

void ft_print_list(t_data *data);

int main(int argc, char **argv)
{
	t_data *test;

	test = (t_data*)malloc(sizeof(t_data));
	test->name = strdup("test.c");
	test->mode = strdup("-rw-r--r--");
	test->date = strdup("Mar 23 10:20");
	test->time = 84980298;
	test->size = 1618;
	test->group_name = strdup("2015_paris");
	test->user_name = strdup("mlevieux");
	test->links = 1;
	test->is_dir = 0;
	test->path = strdup("./");

	ft_print_list(test);
	return (0);
}
