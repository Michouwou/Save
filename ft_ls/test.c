/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:01:06 by mlevieux          #+#    #+#             */
/*   Updated: 2016/03/22 15:24:28 by mlevieux         ###   ########.fr       */
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
#define MOD Stats->st_mode

int main(int argc, char **argv)
{
	struct stat 	*Stats;
	char			*type;
	struct group	*grp;
	struct passwd	*pwd;

	Stats = (struct stat*)malloc(sizeof(struct stat));
	if (!stat(argv[1], Stats))
	{
		pwd = getpwuid(Stats->st_uid);
		grp = getgrgid(Stats->st_gid);
		if (Stats->st_mode & S_IFIFO)
			type = strdup("fifo");
		else if (Stats->st_mode & S_IFCHR)
			type = strdup("peripherique caractere");
		else if (Stats->st_mode & S_IFDIR)
			type = strdup("repertoire");
		else if (Stats->st_mode & S_IFBLK)
			type = strdup("peripherique bloc");
		else if (Stats->st_mode & S_IFREG)
			type = strdup("fichier");
		else if (Stats->st_mode & S_IFLNK)
			type = strdup("lien symbolique");
		else if (Stats->st_mode & S_IFSOCK)
			type = strdup("socket");

		printf("Nom : %s\n", argv[1]);
		fflush(stdout);

		printf("Type : %s\n", type);
		fflush(stdout);

		printf("Mode : %c%c%c%c%c%c%c%c%c\n", MOD & S_IRUSR ? 'r' : '-', MOD & S_IWUSR ? 'w' : '-', MOD & S_IXUSR ? 'x' : '-', MOD & S_IRGRP ? 'r' : '-', MOD & S_IWGRP ? 'w' : '-', MOD & S_IXGRP ? 'x' : '-', MOD & S_IROTH ? 'r' : '-', MOD & S_IWOTH ? 'w' : '-', MOD & S_IXOTH ? 'x' : '-');

		printf("Nombre de liens : %d\n", Stats->st_nlink);
		fflush(stdout);

		printf("Proprietaire : %s\n", pwd->pw_name);
		fflush(stdout);
		
		printf("Groupe : %s\n", grp->gr_name);
		fflush(stdout);
		
		printf("Taille : %lld\n", Stats->st_size / 8);
		fflush(stdout);
		
		printf("Date de derniere modification : %s\n", ctime(&(Stats->st_mtime)));
		fflush(stdout);
	}
	return (0);
}
