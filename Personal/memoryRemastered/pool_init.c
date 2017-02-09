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

#include "pool.h"

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
	int		*first_buffer;

	(void)size;

	// On sauvegarde le tableau actuel
	printf("MDR\n");
	pools_buffer = core->pool->pool;
	total_buffer = core->pool->totalSize;
	used_buffer = core->pool->usedSize;
	number = core->pool->number;
	first_buffer = core->meta->firstPoolIndex;
	// On en alloue un nouveau, plus grand
	printf("Juste avant les allocations\n");
	core->pool->pool = (void**)ft_memalloc(sizeof(void*) * (number + 1));
	core->pool->totalSize = (size_t*)ft_memalloc(sizeof(size_t) * (number + 1));
	core->pool->usedSize = (size_t*)ft_memalloc(sizeof(size_t) * (number + 1));
	core->meta->firstPoolIndex = (int*)ft_memalloc(sizeof(int) * (number + 1));
	i = -1;
	// On copie le precedent dans le nouveau
	printf("Avant la boucle\n");
	while (++i < (int)number)
	{
		core->pool->pool[i] = pools_buffer[i];
		core->pool->totalSize[i] = total_buffer[i];
		core->pool->usedSize[i] = used_buffer[i];
		core->meta->firstPoolIndex[i] = first_buffer[i];
	}
	// On en alloue la derniere case
	printf("Derniere boucle\n");
	core->pool->pool[number] = (t_pool*)ft_memalloc(sizeof(t_pool) * (core->firstAllocatedSize));
	core->pool->totalSize[number] = core->firstAllocatedSize;
	core->pool->number += 1;
	core->meta->firstPoolIndex[number - 1] = core->meta->indexLastGlob + 1;
	core->meta->map[core->meta->firstPoolIndex[number - 1]].poolNumber = number - 1;
	core->meta->map[core->meta->indexLastGlob].next = core->meta->firstPoolIndex[number - 1];
	core->meta->map[core->meta->firstPoolIndex[number - 1]].prev = core->meta->indexLastGlob;
	// On free l'ancien
	printf("Liberation\n");	
	free(total_buffer);
	free(used_buffer);
	free(pools_buffer);
	free(first_buffer);
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
	while (++i < (int)number)
		core->meta->map[i] = glob_array[i];
	core->mapNumber *= 2;
	// On free l'ancienne
	free(glob_array);
}


