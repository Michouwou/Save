/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:44:50 by mlevieux          #+#    #+#             */
/*   Updated: 2016/02/25 10:29:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *str;
	int	i;
	int fds[8];
	int	status[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int	tmp[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int status_sum;

	i = 0;
	fds[0] = open("test_1.txt", O_RDONLY);
	fds[1] = open("test_2.txt", O_RDONLY);
	fds[2] = open("test_3.txt", O_RDONLY);
	fds[3] = open("test_4.txt", O_RDONLY);
	fds[4] = open("test_5.txt", O_RDONLY);
	fds[5] = open("test_6.txt", O_RDONLY);
	fds[6] = open("test_7.txt", O_RDONLY);
	fds[7] = open("test_8.txt", O_RDONLY);
	
	while (i < 8)
	{
		if (fds[i] == -1)
		{
			printf("--- Ouverture du fichier numero %d ratee! Arret du programme ...\n", i + 1);
			fflush(stdout);
			exit(0);
		}
		i++;
	}

	printf("Tout les fichers ont ete ouverts correctement!\n");
	fflush(stdout);

	status_sum = 8;
	while (status_sum > 0)
	{
		if (i == 8)
			i = 0;
		if (status[i] > 0)
			status[i] = get_next_line(fds[i], &str);
		tmp[i] = ((status[i] == 1 || status[i] == 0) && tmp[i] == 1) ? 1 : -1;
		if (status[i] != -1 && tmp[i] == 1)
		{
			printf("\tOn vient de lire |%s| dans le fichier %d et le statut de lecture est de %d\n", str, i + 1, status[i]);
			fflush(stdout);
			if (status[i] == 0)
				tmp[i] = -1;
		}
		else if (status[i] == -1)
		{
			printf("*** Warning : Erreur lors de la lecture dans le fichier %d\n", i + 1);
			fflush(stdout);
			status[i] = 0;
		}
		i++;
		status_sum = 	status[0] +
						status[1] +
						status[2] +
						status[3] +
						status[4] +
						status[5] +
						status[6] +
						status[7];
	}

	printf("Lecture terminee!\n");
	fflush(stdout);
	return (0);
}
