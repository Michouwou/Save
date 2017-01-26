/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:43:12 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/25 18:43:20 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pool.h"

// To allocate the pool.
t_pool		*new_pool(size_t size)
{
	t_pool	*pool;
	
	if (size == 0)
		return (NULL);
	pool = (t_pool*)ft_memalloc(sizeof(t_pool));
	if (pool == NULL)
		return (to_enomem());
	(*pool).pool = ft_memalloc(size);
	if ((*pool).pool == NULL)
	{
		free(pool);
		return (to_enomem());
	}
	(*pool).size = size;
	(*pool).used = 0;
	(*pool).counter = 0;
	return (pool);
}

// Once the pool is allocated using new_pool(size_t), 
// use this function to free it
void		free_pool(t_pool *pool)
{
	free((*pool).pool);
	ft_bzero((void*)pool, sizeof(t_pool));
	free(pool);
	pool = NULL;
}

// Only for convenience, creates a pool which size is DEFAULT_SIZE
t_pool		*create_pool()
{
	return (new_pool(DEFAULT_SIZE));
}
