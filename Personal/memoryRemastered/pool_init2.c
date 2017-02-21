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

void		init_memory(size_t size)
{
	alloc_request(size, 0);
}

void		*new_memory(size_t size)
{
	return (alloc_request(size, 1));
}

void		dump_memory()
{
	alloc_request(0, 2);
}

void		*alloc_request(size_t size, int code)
{
	static t_core	*core;

	if (core == NULL && code == 0)
		// Si size inferieur a 2^24, on le met a une certaine puissance de 2 superieure
		// Les tailles sont arbitraires pour le moment et a revoir bien sur :)
		core = init_core_data(size);
	if (code == 1)
		// On alloue la memoire demadee
		return (intern_user_alloc(size, core));
	if (code == 2)
		dump_pool_memory(core);
	return (NULL);
}

void		*intern_user_alloc(size_t size, t_core *core)
{
	int		i;
	int		free_adress;
	int		flag;

	free_adress = -1;
	flag = 0;
	while (flag < 2)
	{
		// Si flag ne vaut pas zero cela signifie que l'on vient de reallouer une pool,
		// et donc que les autres sont pleines, on va donc directement a la derniere
		i =  flag ? core->pool->number - 1 : 0;
		// Tant qu'on a pas parcouru toutes les pools
		while (i < (int)core->pool->number)
		{
			// On regarde si la pool sur laquelle on est ne contient pas assez de memoire (au total)
			if (core->pool->totalSize[i] - core->pool->usedSize[i] >= size)
				free_adress = intern_get_free_adress(size, core, i); // recupere l'adresse contenant la bonne quantite de memoire
			if (free_adress != -1) // si on a trouve
				return (intern_update_memory_map(core, size, i, free_adress)); // on renvoie le pointeur correspondant apres avoir update la map
			i += 1;
		}
		// Si on a parcouru toutes les pools sans trouver c'est qu'il faut en allouer une autre
		// puis recommencer
		if (flag != 1)
			intern_alloc_new_pool(core, size);
		else
		{
			printf("Ohhhh\n");
			return (NULL); // Si flag vaut 1 c'est que l'on a deja essaye de reallouer une pool mais qu'il n'y a toujours pas assez
		}
		// de place, on renvoie donc NULL pour signifier qu'il y a une erreur
		flag += 1;
	}
	// Si non il y a a eu un probleme alors on renvoie null
	return (NULL);
}

int			intern_get_free_adress(size_t size, t_core *core, int pool_number)
{
	int		i;
	size_t	available;

	// On va directement au premier bloc de mappage correspondant a la pool
	// dans laquelle on cherche une adresse libre
	i = core->meta->firstPoolIndex[pool_number];
	// On calcule la memoire totale restante
	available = core->pool->totalSize[pool_number] - core->pool->usedSize[pool_number];
	// Tant qu'il y a potentiellement au moins un espace contigu de la pool pouvant contenir
	// size octet (premiere condition) et qu'on est pas au bout de notre memoire mappee (deuxieme
	// condition) et qu'on est toujours dans la bonne pool (troisieme condition) et qu'on est soit sur
	// un globule de mappage utilise soit sur un espace de memoire libre mais trop petit (cinquieme
	// condition).
	while (available > size && i < core->meta->indexLastGlob && core->meta->map[i].poolNumber == (size_t)pool_number &&
		(core->meta->map[i].globAdress != NULL || core->meta->map[i].globSize < size))
	{
		// Si c'est un espace non utilise mais trop petit, on soustrait la plage qu'il contient
		// a la memoire totale disponible
		if (core->meta->map[i].globAdress == NULL)
			available -= core->meta->map[i].globSize;
		i = core->meta->map[i].next;
	}
	// Si on est au dernier espace mappe et qu'il nous reste assez d'espace on renvoie le bloc de mappage suivant
	if (available >= size && core->pool->usedSize[pool_number] == 0)
		return (core->meta->firstPoolIndex[pool_number]);
	if (core->meta->map[i].poolNumber != (size_t)pool_number)// && i != core->meta->indexLastGlob)
		return (-1);
	if (i == core->meta->indexLastGlob && available >= size)
		return (i + 1);
	return (i);
}

void		*intern_update_memory_map(t_core *core, size_t size, int pool_number, int free_adress)
{
	// Si il faut mettre le dernier bloc sur le debut d'une pool (la premiere ou une pool fraichement allouee)
	if (free_adress == core->meta->firstPoolIndex[pool_number])
	{
		core->meta->map[core->meta->firstPoolIndex[pool_number]].globAdress = core->pool->pool[pool_number];
		core->pool->usedSize[pool_number] = size;
		core->meta->map[core->meta->firstPoolIndex[pool_number]].globSize = size;
		printf("Last = %d, first = %d\n", core->meta->indexLastGlob, core->meta->firstPoolIndex[pool_number]);
		core->meta->indexLastGlob = core->meta->firstPoolIndex[pool_number];
		return (core->meta->map[core->meta->indexLastGlob].globAdress);
	}
	// Sinon si il faut 'configurer' un nouveau bloc de mappage
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
	// Sinon (donc en fait si c'est un bloc deja "configure" libre contenant au moins size espace memoire)
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
		printf("Pool number : %16d\n", i + 1);
		printf("Total space : %16zd\n", core->pool->totalSize[i]);
		printf("Used space :  %16zd\n", core->pool->usedSize[i]);
		printf("First bloc :  %16d\n", core->meta->firstPoolIndex[i]);
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		j = 1;
		while (j <= (int)core->pool->totalSize[i])
		{
			printf(" %02X%s", (int)(((char*)(core->pool->pool[i]))[j - 1]), j % 32 == 0 ? "\n" : " ");
			j += 1;
		}
		i += 1;
		printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");
	}
}
