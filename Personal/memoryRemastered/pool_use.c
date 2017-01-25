/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_use.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:43:26 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/25 18:43:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pool.h"

// Gets an 'allocation' of size bytes in the pool
void		*pool_alloc(t_pool *pool, size_t size)
{
	void	*alloc;
	size_t	available;
	
	if (pool == NULL || (*pool).pool == NULL)
		return (to_enomem());
	available = (*pool).size - (*pool).used;
	if (available < size)
		return (to_enomem());
	alloc = (*pool).pool + (*pool).used;
	(*pool).used += size;
	(*pool).counter += 1;
	return (alloc);
}

// Returns the number of bytes available in the pool
size_t		pool_state(t_pool *pool)
{
	if (pool == NULL || (*pool).pool == NULL)
		return (0);
	return ((*pool).size - (*pool).used);
}

// Allocates an array of memories from a pool.
// sizes should contain the respective size of each
// allocation, and be 0 terminated. (this means that the
// function will stop at the first encountered zero).
// If the pool does not have enough memory to hold
// all the array, nothing is changed and NULL is returned.
// Be careful not to forget to free yourself the **void
// pointer returned.
void		**pool_arrayAlloc(t_pool *pool, size_t *sizes)
{
	void	**alloc;
	size_t	available;
	int		sizes_len;
	size_t	total;
	
	sizes_len = 0;
	total = 0;
	if (pool == NULL || (*pool).pool == NULL)
		return (to_enomem());
	available = (*pool).size - (*pool).used;
	while (sizes[sizes_len] != 0)
		total += sizes[sizes_len++];
	if (available < total)
		return (to_enomem());
	alloc = ft_memalloc(size(void*) * (size_t)sizes_len);
	(*pool).used += total;
	(*pool).count += sizes_len;
	while (--sizes_len > -1)
	{
		total -= sizes[sizes_len];
		alloc[sizes_len] = (*pool).pool + total;
	}
	return (alloc);
}

// Reset the pool to its initial state
void		to_flat_pool(t_pool *pool)
{
	if (pool == NULL)
		return;
	(*pool).used = 0;
	(*pool).count = 0;
	ft_bzero((*pool).pool, (*pool).size);
}

// Duplicate a pool.
// The brute data is duplicated as well. Nonetheless,
// as for increase_pool(t_pool**, size_t), it is
// strongly recommanded to call restore_adresses(t_pool*, void**)
// on the duplicata of the pool.
t_pool		*pool_dup(t_pool *pool)
{
	t_pool	*duplicate;
	
	if (pool == NULL)
		return (NULL);
	duplicate = new_pool((*pool).size);
	if (duplicate == NULL)
		return (NULL);
	(*duplicate).count = (*pool).count;
	(*duplicate).used = (*pool).used;
	ft_memcopy((*duplicate).pool, (*pool).pool, (*duplicate).size);
	return (duplicate);
}
