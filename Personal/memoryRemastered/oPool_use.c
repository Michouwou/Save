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
	void	*mem;
	int		i;
	
	if (oPool == NULL || (*oPool).pool == NULL)
		return (NULL);
	if ((mem = intern_oPoolAllocation(oPool, size)) == NULL)
		if (intern_oPoolIncreaseSize(oPool, size) == -1 ||
			(mem = intern_oPoolAllocation(oPool, size)) == NULL)
			error_increasingOPool((char*)__PRETTY_FUNCTION__);
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
	(*oPool).sizes[i] = size;
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
	int		cpt;
	size_t	remainingSize;

	if (oPool == NULL)
		return (NULL);
	else if ((*oPool).pool == NULL)
	{
		/************************************************/
		/* If memmap or sizes were not set yet, we only	*/
		/* reserve two places please check using		*/
		/* check_oPoolValidity(). This feature can		*/
		/* nonetheless be useful if you think you are	*/
		/* hardly going to have to store so many things	*/
		/* in your pool and you think it is better to	*/
		/* just want to allocate what is needed at a	*/
		/* certain moment.								*/
		/* See MANUAL/t_oPool.txt for examples.			*/
		/************************************************/
		if (((*oPool).pool = ft_memalloc(size)) == NULL)
			return (to_enomem());
		if ((*oPool).memmap == NULL &&
			((*oPool).memmap = (void**)ft_memalloc(sizeof(void*) * 2)) == NULL)	
			return (to_enomem());
		if ((*oPool).sizes == NULL &&
			((*oPool).sizes = (size_t*)ft_memalloc(sizeof(size_t) * 2)) == NULL)
			return (to_enomem());
		(*oPool).self_size = size;
		(*oPool).self_used = size;
		(*oPool).len == 0 ? (*oPool).len = 2;
		return ((*oPool).pool);
	}
	else if ((remainingSize = (*oPool).self_size - (*oPool).self_used) > size)
	{
		cpt = -1;
		while (++cpt < (*oPool).len && ((*oPool).memmap[cpt] ||
			(*oPool).sizes[cpt]) && ((*oPool).sizes[cpt] < size ||
			(*oPool).memmap[cpt] == NULL))
			if ((*oPool).memmap[cpt] == NULL && (*oPool).sizes[cpt] > 0)
				remainingSize -= (*oPool).sizes[cpt];
		if (remainingSize < size && force_oPoolDefrag(oPool) != -1)
			return ((*oPool).pool + (*oPool).self_used + 1);
		else if (remainingSize < size)
			error_defragmentingOPool((char*)__PRETTY_FUNCTION__);
		return ((*oPool).memmap[cpt ? cpt - 1 : cpt] + (cpt ? (*oPool).sizes[cpt - 1] : 0))
	}
	return (NULL);
}

int			intern_oPoolIncreaseSize(t_oPool *oPool, size_t size)
{
	(void)oPool;
	(void)size;
	return (1);
}