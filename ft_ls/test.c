/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/22 11:26:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

int main(void)
{
	DIR *directory;
	DIR *sub;
	struct dirent *cursor;
	struct dirent *tmp;

	directory = opendir(".");
	cursor = readdir(directory);
	while (cursor != NULL)
	{
		printf("%s, %d\n", cursor->d_name, DTTOIF(cursor->d_type));
		if ((sub = opendir(cursor->d_name)) != NULL && strcmp(cursor->d_name, "."))
		{
			while ((tmp = readdir(sub)) != NULL)
				printf("\n\t%s", tmp->d_name);
			closedir(sub);
			printf("\n");
		}
		cursor = readdir(directory);
	}
	printf("\n");
	closedir(directory);
	return (0);
}
