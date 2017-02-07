/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:36:35 by mlevieux          #+#    #+#             */
/*   Updated: 2017/02/07 17:37:09 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

void		*alloc_request(size_t size, int code)
{
	static t_core	*core;

	if (core == NULL)
	{
		// Si size inferieur a 2^24, on le met a une certaine puissance de 2 superieure
		// Les tailles sont arbitraires pour le moment et a revoir bien sur :)
		printf("Initiatilzation\n");
		core = init_core_data(size * 32);
	}
	if (code == 1)
	{
		// On alloue la memoire demadee
		printf("Allocation\n");
		return (intern_user_alloc(size, core));
	}
	if (code == 2)
		dump_pool_memory(core);
	return (NULL);
}

void		*intern_user_alloc(size_t size, t_core *core)
{
	int		i;
	int		free_adress;
	_Bool	flag;

	free_adress = 0;
	flag = FALSE;
	while (!flag)
	{
		i = 0;
		if (free_adress != 0)
			flag = TRUE;
		// Tant qu'on a pas parcouru toutes les pools
		while (i < (int)core->pool->number)
		{
			printf("Looking for free space\n");
			// On regarde si la pool sur laquelle on est ne contient pas assez de memoire (au total)
			if (core->pool->totalSize[i] - core->pool->usedSize[i] >= size)
				free_adress = intern_get_free_adress(size, core, i); // recupere l'adresse contenant la bonne quantite de memoire
			printf("Checking if free space exists\n");
			if (free_adress != -1) // si on a trouve
				return (intern_update_memory_map(core, size, i, free_adress)); // on renvoie le pointeur correspondant apres avoir update la map
			i += 1;
		}
		// Si on a parcouru toutes les pools sans trouver c'est qu'il faut en allouer une autre
		intern_alloc_new_pool(core, size);
	}
	// Si non il y a a eu un probleme alors on renvoie null
	return (NULL);
}

int			intern_get_free_adress(size_t size, t_core *core, int pool_number)
{
	int		i;
	size_t	available;

	i = core->meta->firstPoolIndex[pool_number];
	available = core->pool->totalSize[pool_number] - core->pool->usedSize[pool_number];
	printf("Before intern_get_free_adress loop\n");
	while (available > size && i < core->meta->indexLastGlob && core->meta->map[i].poolNumber == (size_t)pool_number &&
		(core->meta->map[i].globAdress != NULL || core->meta->map[i].globSize < size))
	{
		available -= core->meta->map[i].globSize;
		i = core->meta->map[i].next;
		printf("One tour inside looop\n");
	}
	if (i == core->meta->indexLastGlob && available > size)
		return (i + 1);
	printf("No new adress to be given\n");
	if (core->meta->map[i].poolNumber != (size_t)pool_number)
		return (-1);
	printf("Returning index\n");
	return (i);
}

void		*intern_update_memory_map(t_core *core, size_t size, int pool_number, int free_adress)
{
	if (free_adress == 0)
	{
		core->meta->map[0].globAdress = core->pool->pool[0];
		core->pool->usedSize[0] = size;
		core->meta->map[0].globSize = size;
		core->meta->indexLastGlob = 0;
		return (core->meta->map[0].globAdress);
	}
	else if (free_adress > core->meta->indexLastGlob)
	{
		core->meta->map[core->meta->indexLastGlob].next = free_adress;
		core->meta->map[free_adress].prev = core->meta->indexLastGlob;
		core->meta->indexLastGlob = free_adress;
		core->meta->map[free_adress].globSize = size;
		core->meta->map[free_adress].globAdress = core->meta->map[core->meta->map[free_adress].prev].globAdress +
													core->meta->map[core->meta->map[free_adress].prev].globSize;
		if ((size_t)free_adress == core->mapNumber - 1)
			intern_alloc_new_map(core);
		core->pool->usedSize[pool_number] += size;
		return (core->meta->map[free_adress].globAdress);
	}
	else
	{
		core->meta->map[free_adress].globAdress = core->meta->map[core->meta->map[free_adress].prev].globAdress +
													core->meta->map[core->meta->map[free_adress].prev].globSize;
		core->meta->map[free_adress].globSize = size;
		core->pool->usedSize[pool_number] += size;
		return (core->meta->map[free_adress].globAdress);
	}
}

void		dump_pool_memory(t_core *core)
{
	int		i;
	int		j;

	i = 0;
	while (i < (int)core->pool->number)
	{
		j = 1;
		while (j <= (int)core->pool->totalSize[i])
		{
			printf(" %02X%s", (int)(((char*)(core->pool->pool[i]))[j - 1]), j % 32 == 0 ? "\n" : " ");
			j += 1;
		}
		i += 1;
	}
}
