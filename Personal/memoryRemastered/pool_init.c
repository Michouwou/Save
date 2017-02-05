/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poolInit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:30:27 by mlevieux          #+#    #+#             */
/*   Updated: 2017/02/02 18:30:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pool.h>

t_metadata	*new_meta_data(void)
{
	t_metadata	*meta;

	meta = (t_metadata*)ft_memalloc(sizeof(t_metadata));
	meta->map = (t_glob*)ft_memalloc(sizeof(t_glob) * GLOB_INITIAL_NUMBER);
	meta->firstPoolIndex = (int*)ft_memalloc(sizeof(int));
	meta->firstPoolIndex[0] = 0;
	meta->indexLastGlob = -1;
	return (meta);
}

t_core		*init_core_data(size_t size)
{
	t_core		*core;
	t_pool		*pool;
	t_metadata	*meta;

	// On alloue core
	core = (t_core*)ft_memalloc(sizeof(t_core));

	// On initialise la metadonnee
	meta = new_meta_data();

	// On initialize la pool
	pool = (t_pool*)ft_memalloc(sizeof(t_pool));
	pool->pool = (void**)ft_memalloc(sizeof(void*));
	pool->pool[0] = (void*)ft_memalloc(size);
	pool->number = (size_t)1;
	pool->totalSize = (size_t*)ft_memalloc(sizeof(size_t));
	pool->totalSize[0] = size;
	pool->usedSize = (size_t*)ft_memalloc(sizeof(size_t));

	// On set les valeurs dans core
	core->pool = pool;
	core->meta = meta;
	core->firstAllocatedSize = size;
	core->mapNumber = GLOB_INITIAL_NUMBER;

	// On renvoie
	return (core);
}

void		intern_alloc_new_pool(t_core *core, size_t size)
{
	void	**pools_buffer;
	int		i;
	size_t	number;
	size_t	*total_buffer;
	size_t	*used_buffer;

	// On sauvegarde le tableau actuel
	pools_buffer = core->pool->pool;
	total_buffer = core->pool->totalSize;
	used_buffer = core->pool->usedSize;
	number = core->pool->number;
	// On en alloue un nouveau, plus grand
	core->pool->pool = (void**)ft_memalloc(sizeof(void*) * (number + 1));
	core->pool->totalSize = (size_t*)ft_memalloc(sizeof(size_t) * (number + 1));
	core->pool->usedSize = (size_t*)ft_memalloc(sizeof(size_t) * (number + 1));
	i = -1;
	// On copie le precedent dans le nouveau
	while (++i < number)
	{
		core->pool->pool[i] = pools_buffer[i];
		core->pool->totalSize[i] = total_buffer[i];
		core->pool->usedSize[i] = used_buffer[i];
	}
	// On en alloue la derniere case
	core->pool->pool[number] = (t_pool*)ft_memalloc(sizeof(t_pool) * (core->firstAllocatedSize));
	core->pool->totalSize[number] = core->firstAllocatedSize;
	core->pool->number += 1;
	// On free l'ancien
	free(pools_buffer);
}

void		intern_alloc_new_map(t_core *core)
{
	t_glob		*glob_array;
	int			i;
	size_t		number;

	// On sauvegarde les maps actuelles
	glob_array = core->meta->map;
	number = core->mapNumber;
	i = -1;
	// On alloue un nouveau tableau
	core->meta->map = (t_glob*)ft_memalloc(sizeof(t_glob) * (number * 2));
	// On copie l'ancien
	while (++i < number)
		core->meta->map[i] = glob_array[i];
	core->mapNumber *= 2;
	// On free l'ancienne
	free(glob_array);
}

void		*alloc_request(size_t size, int code)
{
	static t_core	*core;

	if (core == NULL)
	{
		// Si size inferieur a 2^24, on le met a une certaine puissance de 2 superieure
		// Les tailles sont arbitraires pour le moment et a revoir bien sur :)
		printf("Initiatilzation\n");
		core = init_core_data(size * 128);
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
	while (!flag)
	{
		i = 0;
		if (free_adress != 0)
			flag = FALSE;
		// Tant qu'on a pas parcouru toutes les pools
		while (i < core->pool->number)
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
	while (available > size && i < core->meta->indexLastGlob && core->meta->map[i].poolNumber == pool_number &&
		(core->meta->map[i].globAdress != NULL || core->meta->map[i].globSize < size))
	{
		available -= core->meta->map[i].globSize;
		i = core->meta->map[i].next;
		printf("One tour inside looop\n");
	}
	if (i == core->meta->indexLastGlob && available > size)
		return (i + 1);
	printf("No new adress to be given\n");
	if (core->meta->map[i].poolNumber != pool_number)
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
		if (free_adress == core->mapNumber - 1)
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
	while (i < core->pool->number)
	{
		j = 1;
		while (j <= core->pool->totalSize[i])
		{
			printf("%3X%s", (int)(((char*)(core->pool->pool[i]))[j - 1]), j % 32 == 0 ? "\n" : " ");
			j += 1;
		}
		i += 1;
	}
}