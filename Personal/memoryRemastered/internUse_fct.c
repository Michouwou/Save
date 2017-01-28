/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internUse_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:19 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/26 17:19:34 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pool.h"

// To set errno to ENOMEM in case the pool is not
// big enough. For internal use only.
void		*to_enomem()
{
	errno = ENOMEM;
	return (NULL);
}

void		error_increasingOPool(char *path)
{
	ft_putstr("Enable to allocate oPool asked memory in function : ");
	ft_putstr(path);
	exit(-1);
}

void		error_defragmentingOPool(char* path)
{
	ft_putstr("Error trying to defragment memory in function : ");
	ft_putstr(path);
	exit(-1);
}

void						intern_oPoolMapNewChunk(t_memoryMapper *memoryMap, t_oPool *oPool, void *mem, size_t size)
{
	t_memoryMapper	*tmp;
	t_memoryMapper	nNode; // Nothing complicated, just stands for "new node"

	printf("map = %p ;\n", memoryMap);
	printf("map.memoryChunk = %p ;\nmap.chunkSize = %zd ;\n", (*memoryMap).memoryChunk, (*memoryMap).chunkSize);
	if ((*memoryMap).memoryChunk == NULL)
	{
		(*memoryMap).memoryChunk = (*oPool).pool;
		(*memoryMap).chunkSize = size;
		(*memoryMap).next = NULL;
		return;
	}
	nNode.memoryChunk = mem;
	nNode.chunkSize = size;
	nNode.next = NULL;
	tmp = memoryMap;
	while ((*tmp).next)
		tmp = (*tmp).next;
	(*tmp).next = &nNode;
}

void						intern_oPoolUpdateChunk(t_memoryMapper *map, void *mem, size_t size)
{
	t_memoryMapper	nNode;

	if ((*map).chunkSize < size)
	{
		nNode.memoryChunk = NULL;
		nNode.chunkSize = size - (*map).chunkSize;
		nNode.next = (*map).next;
		(*map).next = &nNode;
	}
	(*map).memoryChunk = mem;
	(*map).chunkSize = size;
}

t_memoryMapper				*intern_oPoolGetMappedIndex(t_memoryMapper *memoryMap, size_t chunk)
{
	t_memoryMapper	*tmp;
	int				i;

	i = 1;
	tmp = memoryMap;
	while (i <= chunk && tmp)
		tmp = (*tmp).next;
	return (tmp);
}