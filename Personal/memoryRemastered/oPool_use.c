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
	return (mem);
}

// To access a precise chunk of an oPool memory,
// works a little like an array.
void		*oPool_indexBaseAcces(t_oPool *oPool, size_t index)
{
	if (oPool == NULL || index > (*oPool).len)
		return (NULL);
	return ((*oPool).memmap[index]);
}

// Puts a whole chunk of the oPool back to 0
void		del_oPool_chunk(t_oPool *oPool, size_t chunk)
{
	void	*mem;
	
	mem = oPool_indexBaseAcces(oPool, chunk);
	if (mem != NULL)
	{
		ft_bzero(mem, (*oPool).sizes[chunk]);
		(*oPool).memmap[chunk] = NULL;
	}
}

void		*intern_oPoolAllocation(t_oPool *oPool, size_t size)
{
	size_t			remainingSize;
	t_memoryMapper	*map;
	void			*mem;

	map = (*oPool).memoryMap;
	mem = (*map).memoryChunk;
	remainingSize = (*oPool).self_size - (*oPool).self_used;
	if (oPool == NULL || (*oPool).pool == NULL)
		return (NULL);
	while (map && ((*map).memoryChunk != NULL || (*map).chunkSize < size))
	{
		mem += (*map).size;
		if ((*map).memoryChunk == NULL)
			remainingSize -= (*map).size;
		map = (*map).next;
	}
	if (remainingSize > size)
	{
		if (map == NULL)
		{
			intern_oPoolMapNewChunk((*oPool).memoryMap, (*oPool).pool, size);
			return ((*oPool).pool);
		}
		else if (map != NULL)
		{
			intern_oPoolUpdateChunk(map, mem, size);
			return (mem);
		}
	}
	return (NULL);
}

// Codes : -1 for invalid t_oPool for use, 0 for valid
// but not complete t_oPool structure,
// 1 for valid t_oPool for use.
int			check_oPoolValidity(t_oPool *oPool)
{
	if (oPool == NULL ||
		(int)((*oPool).self_size - (*oPool).self_used) < 0)
		return (-1);
	if ((*oPool).pool == NULL ||
		(*oPool).memmap == NULL ||
		(*oPool).sizes == NULL ||
		(*oPool).len == 0 ||
		(*oPool).self_size)
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