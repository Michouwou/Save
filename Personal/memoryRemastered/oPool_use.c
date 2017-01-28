/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oPool_use.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:42:53 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/25 18:43:05 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pool.h"

// To allocate a size bytes memory from an
// oPool. If the pool is too small, its size
// will automatically be increased, as well
// as for the original number of chunks
// it is supposed to be able to hold.
void		*oPool_alloc(t_oPool *oPool, size_t size)
{
	void			*mem;
	//int		i;
	
	if (oPool == NULL || (*oPool).pool == NULL)
		return (NULL);
	if ((mem = intern_oPoolAllocation(oPool, size)) == NULL)
		if (intern_oPoolIncreaseSize(oPool, size) == -1 ||
			(mem = intern_oPoolAllocation(oPool, size)) == NULL)
			error_increasingOPool((char*)__PRETTY_FUNCTION__);
	/*	Changing void ** + size_t * by t_memoryMapper
		but keeping old code for the moment
	i = 0;
	while (i < (int)(*oPool).len && (*oPool).memmap[i] != NULL)
		i++;
	if (i == (*oPool).len)
	{
		// We multiply the len attribute by two, which is a totally arbitrary number
		// so we put our confidence into the discerning of the user to carefully
		// choose the original len...
		if (((*oPool).memmap = ft_memshift(ft_memalloc(sizeof(void*) * (i * 2)), oPool->memmap, sizeof(void*) * i)) == NULL)
			error_increasingOPool((char*)__PRETTY_FUNCTION__);
		if (((*oPool).sizes = ft_memshift(ft_memalloc(sizeof(size_t) * (i * 2)), oPool->sizes, sizeof(size_t) * i)) == NULL)
			error_increasingOPool((char*)__PRETTY_FUNCTION__);
		(*oPool).len *= 2;
	}
	(*oPool).memmap[i] = mem;
	(*oPool).sizes[i] = size; */
	(*oPool).self_used += size;
	return (mem);
}

// To access a precise chunk of an oPool memory,
// works a little like an array.
void		*oPool_indexBaseAcces(t_oPool *oPool, size_t index)
{
	t_memoryMapper	*tmp;

	if (oPool == NULL)// || index > (*oPool).len)
		return (NULL);
	tmp = intern_oPoolGetMappedIndex((*oPool).memoryMap, index);
	return ((*tmp).memoryChunk);
}

// Puts a whole chunk of the oPool back to 0
void		del_oPool_chunk(t_oPool *oPool, size_t chunk)
{
	t_memoryMapper	*mem;
	
	mem = intern_oPoolGetMappedIndex((*oPool).memoryMap, chunk);
	if (mem != NULL)
	{
		ft_bzero((void*)(*mem).memoryChunk, (*mem).chunkSize);
		(*mem).memoryChunk = NULL;
	}
}

void		*intern_oPoolAllocation(t_oPool *oPool, size_t size)
{
	size_t			remainingSize;
	t_memoryMapper	*map;
	void			*mem;

	printf("Entree dans la fonction d'allocation\n");
	map = (*oPool).memoryMap; // For travelling in the list
	mem = (*map).memoryChunk; // To know what adress to return
	remainingSize = (*oPool).self_size - (*oPool).self_used; // Size that is still available
	if (oPool == NULL || (*oPool).pool == NULL) // If Nothing
		return (NULL);

	printf("Les premieres valeurs sont sets, on entre dans la boucle, map = %zd\n", map->chunkSize);
	while (map && ((*map).memoryChunk != NULL || (*map).chunkSize < size))
		// while we're not at the end and either the space is already in use or there is not enough space to allocate size
	{
		mem += (*map).chunkSize; // We increment the adress
		if ((*map).memoryChunk == NULL) // If the poiter memoryChumk is NULL but the space is too small to put
			// size bytes in it then it represents some free memory that we counted as available, which is then
			// not really true, so we just do as if this memory was really taken to fix this problem
			remainingSize -= (*map).chunkSize;
		map = (*map).next;
	}

	printf("On est sorti indemne de la boucle\n");
	if (remainingSize > size) // If after all this there is still enough space
	{
		if (map == NULL) // If it was the end of the list (no hole in the memory is big enough to hold size)
		{
			intern_oPoolMapNewChunk((*oPool).memoryMap, oPool, mem, size); // we create a new node
			return ((*oPool).pool);
		}
		else if (map != NULL) // If it wasn't (there is a hole that is big enough)
		{
			intern_oPoolUpdateChunk(map, mem, size); // We update this node
			return (mem);
		}
	}
	printf("Sortie de la fonction d'allocation\n");
	return (NULL); // last case there is no possibility to allocate, just return NULL
}

// Codes : -1 for invalid t_oPool for use, 0 for valid
// but not complete t_oPool structure,
// 1 for valid t_oPool for use.
int			check_oPoolValidity(t_oPool *oPool)
{
	if (oPool == NULL ||
		(int)((*oPool).self_size - (*oPool).self_used) < 0)
		return (-1);
	if ((*oPool).pool == NULL /*||
		(*oPool).memmap == NULL ||
		(*oPool).sizes == NULL ||
		(*oPool).len == 0 ||*/
		|| (*oPool).self_size == 0)
		return (0);
	return (1);
}

int			intern_oPoolIncreaseSize(t_oPool *oPool, size_t size)
{
	(void)oPool;
	(void)size;
	return (1);
}

int			force_oPoolDefrag(t_oPool *oPool)
{
		(void)oPool;
		return (-1);
}