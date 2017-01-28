/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oPool_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:42:31 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/25 18:42:49 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pool.h"

// Inits a t_oPool pointer pointing to a t_oPool structure
// able to hold size bytes of memory.
// Len is the number adresses that the oPool is initially
// going to be able to hold (but will be increased automatically
// if it reveals necessary).
t_oPool		*init_oPool(size_t size, size_t len)
{
	t_oPool			*oPool;
	t_memoryMapper	map;
	
	oPool = (t_oPool*)ft_memalloc(sizeof(t_oPool));
	ft_bzero((void*)&map, sizeof(t_memoryMapper));
	if (oPool == NULL)
		return (to_enomem());
	//(*oPool).memmap = (void**)ft_memalloc(sizeof(void*) * (len));
	//(*oPool).sizes = (size_t*)ft_memalloc(sizeof(size_t) * (len));
	(*oPool).pool = ft_memalloc(size);
	if (//(*oPool).memmap == NULL ||
		(*oPool).pool == NULL)// ||
		//(*oPool).sizes == NULL)
	{
		free_oPool(oPool);
		return (to_enomem());
	}
	//(*oPool).len = len;
	(*oPool).self_size = size;
	(*oPool).self_used = 0;
	(*oPool).memoryMap = &map;
	return (oPool);
}

// To conveniently free an oPool structure
void		free_oPool(t_oPool *oPool)
{
	int		i;
	
	if (oPool != NULL)
	{
		i = 0;
		free_pool((*oPool).pool);
		//while (i < (*oPool).len)
		//	free((*oPool).memmap[i++]);
		//free((*oPool).memmap);
	}
	//ft_bzero((void*)(*oPool).sizes, sizeof(size_t) * (*oPool).len);
	ft_bzero((void*)oPool, sizeof(oPool));
	free(oPool);
	oPool = NULL;
}
