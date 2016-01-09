/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:44:50 by mlevieux          #+#    #+#             */
/*   Updated: 2015/12/20 17:22:47 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *str;
	int fd;
	int fd2;

	fd = open("text.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	fd2 = open("text2.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	if (fd > -1 && fd2 > -1)
	{
		str = (char*)malloc(sizeof(char) * 200);
		get_next_line(fd, &str);
		printf("%s\n", str);
		get_next_line(fd2, &str);
		printf("%s\n", str);
		get_next_line(fd, &str);
		printf("%s\n", str);
		get_next_line(fd2, &str);
		printf("%s\n", str);
	}
	return (0);
}
