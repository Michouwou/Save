/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:43:42 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/26 18:39:33 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _T_POOL_H
# define _T_POOL_H

# include "libft.h"
# include <stdlib.h>
# include <errno.h>
# include <stddef.h>

// /!\ TO DEBUGG ONLY, THINK OF GETTING IT AWAY /!\ \\

# include <stdio.h>

/************************************************************************/
/*																		*/
/* Implementation of a 'pool' library. The goal not being to get a		*/
/* code for extensive use of this pool everywhere but just to simplify	*/
/* allocation and use of memory in 'no-performance-needed'-programs		*/
/* the first implementation of the lib will not include exhaustive		*/
/* functions for the use of the pool. Nonetheless, the lib will			*/
/* certainly be extended later on.										*/
/*																		*/
/* NOTHING IS TESTED YET.												*/
/* Next ameliorations :													*/
/* 	- Add a 'sizes' array to the t_oPool structure to keep track of how	*/
/* much memory each chunk takes at any point of execution.				*/
/*	- Change implementation of 'oPool_alloc()' so that it will look if	*/
/* there are unused spaces in the memory, large enough, to insert the	*/
/* demanded size in it, rather than just putting it to the end.			*/
/*	- Add a 'defrag' function to t_oPool to compact all the memory and	*/
/* leave no holes in the middle of it.									*/
/*																		*/
/************************************************************************/

#define DEFAULT_SIZE 800

// Nested list for memory mapping
typedef struct				s_memoryMapper
{
	void					*memoryChunk;
	size_t					chunkSize;
	size_t					poolRange;
	struct s_memoryMapper	*next;
}							t_memoryMapper;

// Simple pool for basic use. It's a one-dimension memory set
// that handles itself in terms of capacity and memory
// gestion.
typedef struct				s_pool
{
	void					*pool;
	size_t					size;
	size_t					used;
	size_t					counter;
}							t_pool;

// More complex structure. It contains a pool of data
// structures and a bi-dimension set of maps, 
// reprensenting the way each pool's memory is used at
// any point of the execution. It fixes the majority of
// the problems inherent to the implementation of t_pool.
// The cost of it is a huge performance decrease.
typedef struct				s_olympic_pool
{
	void					*pool;
	t_memoryMapper			*memoryMap;
	size_t					self_size;
	size_t					self_used;
}							t_oPool;

// For internal use only
void						error_increasingOPool(char *path);
void						error_defragmentingOPool(char* path);
void						*intern_oPoolAllocation(t_oPool *oPool, size_t size);
int							intern_oPoolIncreaseSize(t_oPool *oPool, size_t size);
void						*to_enomem();
void						intern_oPoolMapNewChunk(t_memoryMapper *memoryMap, void *mem, size_t size);
void						intern_oPoolUpdateChunk(t_memoryMapper *map, void *mem, size_t size);
t_memoryMapper				*intern_oPoolGetMappedIndex(t_memoryMapper *memoryMap, size_t chunk);

// For t_pool struct only
t_pool						*new_pool(size_t size);
void						free_pool(t_pool *pool);
t_pool						*create_pool();
void						*pool_alloc(t_pool *pool, size_t size);
size_t						pool_state(t_pool *pool);
void						**pool_arrayAlloc(t_pool *pool, size_t *sizes);
void						to_flat_pool(t_pool *pool);
t_pool						*pool_dup(t_pool *pool);

// For t_oPool struct only
t_oPool						*init_oPool(size_t size, size_t len);
void						free_oPool(t_oPool *oPool);
void						*oPool_alloc(t_oPool *oPool, size_t size);
void						*oPool_indexBaseAcces(t_oPool *oPool, size_t index);
void						del_oPool_chunk(t_oPool *oPool, size_t chunk);
int							force_oPoolDefrag(t_oPool *oPool);

#endif
