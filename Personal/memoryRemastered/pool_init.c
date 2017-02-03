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
	meta[0].map[GLOB_INITIAL_NUMBER - 1].next = -1;
	return (meta);
}

t_core		*init_core_data(size_t size)
{
	t_core		*core;
	t_pool		*pool;
	t_metadata	*meta;

	// On alloue core
	core = (t_core*)ft_memalloc(sizeof(t_core));

	// On initialize la pool
	pool = (t_pool*)ft_memalloc(sizeof(t_pool));
	pool->pool = (void**)ft_memalloc(sizeof(void*));
	pool->pool[0] = (void*)ft_memalloc(size);
	pool->number = (size_t)1;
	pool->totalSize = (size_t*)ft_memalloc(sizeof(size_t));
	pool->totalSize[0] = size;
	pool->usedSize = (size_t*)ft_memalloc(sizeof(size_t));

	// On initialise la metadonnee
	meta = new_meta_data();

	// On set les valeurs dans core
	core->pool = pool;
	core->meta = meta;
	core->firstAllocatedSize = size;
	core->mapNumber = (size_t)1;

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
	t_metadata	*meta_array;
	int			i;
	size_t		number;

	// On sauvegarde les maps actuelles
	meta_array = core->meta;
	number = core->mapNumber;
	i = -1;
	// On alloue un nouveau tableau
	core->meta = (t_metadata*)ft_memalloc(sizeof(t_metadata) * (number + 1));
	// On copie l'ancien
	while (++i < number)
		core->meta[i] = meta_array[i];
	core->mapNumber += 1;
	// On cree la map correspondant au dernier index
	core->meta[number].map[GLOB_INITIAL_NUMBER - 1].next = -1;
	// On free l'ancienne
	free(meta_array);
}

void		*alloc_request(size_t size)
{
	static t_core	*core;

	if (core == NULL)
	{
		// Si size inferieur a 2^24, on le met a une certaine puissance de 2 superieure
		// Les tailles sont arbitraires pour le moment et a revoir bien sur :)
		if (size < 0xF0)
			size = 0xF0;
		else if (size < 0xF000)
			size = 0xF000;
		else if (size < 0xF00000)
			size = 0xF00000;
		core = init_core_data(size);
	}
	// On alloue la memoire demadee
	return (intern_user_alloc(size, core));
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
			// On regarde si la pool sur laquelle on est ne contient pas assez de memoire (au total)
			if (core->pool->totalSize - core->pool->usedSize >= size)
				free_adress = intern_get_free_adress(size, core, i); // recupere l'adresse contenant la bonne quantite de memoire
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