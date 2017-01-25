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
	if ((mem = intern_oPoolAllocation(*oPool, size)) == NULL)
		if (intern_oPoolIncreaseSize(oPool, size) == -1 ||
			(mem = intern_oPoolAllocation(oPool, size)) == NULL)
			error_increasingOPool(__PRETTY_FUNCTION__);
	i = 0;
	while (i < (int)(*oPool).len && (*oPool).memmap[i] != NULL)
		i++;
	if (i == (*oPool).len)
	{
		// We multiply the len attribute by two, which is a totally arbitrary number
		// so we put our confidence into the discerning of the user to carefully
		// choose the original len...
		if (((*oPool).memmap = ft_memshift(ft_memalloc(sizeof(void*) * (i * 2)), oPool->memmap, sizeof(void*) * i)) == NULL)
			error_increasingOPool(__PRETTY_FUNCTION__);
		if (((*oPool).sizes = ft_memshift(ft_memalloc(sizeof(size_t) * (i * 2)), oPool->sizes, sizeof(size_t) * i)) == NULL)
			error_increasingOPool(__PRETTY_FUNCTION__);
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
		ft_bzero(mem, sizes[chunk]);
		(*oPool).memmap[chunk] = NULL;
	}
}
