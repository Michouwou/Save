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
/*	- Change implementation of t_oPool to break encapsulation and have	*/
/* no more dependency on the t_pool implementation.						*/
/*																		*/
/************************************************************************/

#define DEFAULT_SIZE 800

// Simple pool for basic use. It's a one-dimension memory set
// that handles itself in terms of capacity and memory
// gestion.
typedef struct		s_pool
{
	void			*pool;
	size_t			size;
	size_t			used;
	size_t			counter;
}					t_pool;

// More complex structure. It contains a pool of data
// structures and a bi-dimension set of maps, 
// reprensenting the way each pool's memory is used at
// any point of the execution. It fixes the majority of
// the problems inherent to the implementation of t_pool.
// The cost of it is a huge performance decrease.
typedef struct		s_olympic_pool
{
	void			*pool;
	void			**memmap;
	size_t			*sizes;
	size_t			len;
}					t_oPool;


// To set errno to ENOMEM in case the pool is not
// big enough. For internal use only.
void		*to_enomem()
{
	errno = ENOMEM;
	return (NULL);
}

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
	ft_bzero((void*)pool);
	free(pool);
}

// Only for convenience, creates a pool which size is DEFAULT_SIZE
t_pool		*create_pool()
{
	return (new_pool(DEFAULT_SIZE));
}

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

// To increase a pool size. For performance concerns,
// it'd be great to avoid using this function
// when there are alternatives. Return will be -1 on error,
// 0 if nothing was done, 1 on success.
// There's a high probability that the previous allocations,
// in terms of memory adresses, will not be usable anymore
// after a call to this function.
// It is then adviced to call restore_adresses(t_pool*, void**)
// after a call to this function on a pool that had already allocated
// memory.
// This function handles none-yet-allocated pools.
int			increase_pool(t_pool **pool, size_t size)
{
	t_pool	*new_pool;
	
	if (pool == NULL)
		return (0);
	if (*pool != NULL && (**pool).size >= size)
		return (0);
	new_pool = new_pool(size);
	if (new_pool == NULL)
		return (-1);
	if (*pool != NULL)
	{
		new_pool.used = (**pool).used;
		new_pool.count = (**pool).count;
		ft_memcopy(new_pool, (const void*)(**pool).pool, (**pool).size);
		free_pool(*pool);
		*pool = NULL;
	}
	*pool = new_pool;
	return (1);
}

// To restore integrity of previously allocated memories
// after having increased pool size. This is a quite none
// convenient and memory eating operation. To avoid then.
// Previous has to be an array containing all the previous
// memory adresses returned. It will be filled with the
// new adresses, so that no data's lost.
// Moreover this array has to be NULL terminated.
void		restore_adresses(t_pool *pool, void **previous)
{
	int				i;
	unsigned int	tmp;
	
	i = 0;
	if (pool == NULL or previous == NULL)
		return;
	tmp = (unsigned int)previous[0];
	while (previous[i] != NULL)
	{
		previous[i] = (*pool).pool + ((unsigned int)previous[i] - tmp);
		i += 1;
	}
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

// Inits a t_oPool pointer pointing to a t_oPool structure
// able to hold size bytes of memory.
// Len is the number adresses that the oPool is initially
// going to be able to hold (but will be increased automatically
// if it reveals necessary).
t_oPool		*init_oPool(size_t size, size_t len)
{
	t_oPool	*oPool;
	
	oPool = (t_oPool*)ft_memalloc(sizeof(t_oPool));
	if (oPool == NULL)
		return (to_enomem());
	(*oPool).memmap = (void**)ft_memalloc(sizeof(void*) * (len));
	(*oPool).sizes = (size_t*)ft_memalloc(sizeof(size_t) * (len));
	(*oPool).pool = ft_memalloc(size);
	if ((*oPool).memmap == NULL ||
		(*oPool).pool == NULL ||
		(*oPool)..sizes == NULL)
	{
		free_oPool(oPool);
		return (to_enomem());
	}
	(*oPool).len = len;
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
		while (i < (*oPool).len)
			free((*oPool).memmap[i++]);
		free((*oPool).memmap);
	}
	ft_bzero((*oPool).sizes, sizeof(size_t) * (*oPool).len);
	ft_bzero(oPool, sizeof(oPool));
	free(oPool);
	oPool = NULL;
}

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

void		error_increasingOPool(char *path)
{
	ft_putstr("Enable to allocate oPool asked memory in function : ");
	ft_putstr(path);
	exit(-1);
}

// /!\ THIS IS TO MOVE TO THE BASIC FUNCTIONS OF LIBFT. /!\
// Copies the memory from src to dst before freeing src
// and finally remove the pointer to dst
void		*ft_memshift(void *dst, const void *src, size_t n)
{
	ft_memcopy(dst, src, n);
	free(src);
	return (dst);
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