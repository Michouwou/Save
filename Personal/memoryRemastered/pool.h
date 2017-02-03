/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:58:15 by mlevieux          #+#    #+#             */
/*   Updated: 2017/02/02 17:58:17 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POOL_H
# define _POOL_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

# define GLOB_INITIAL_NUMBER 512
# define TRUE 1
# define FALSE 0

// [a-z_]+\t+\*?[a-z_]+\(.+\) (regex pour trouver les fonctions)

typedef	struct		s_glob
{
	void			*globAdress;
	size_t			globSize;
	size_t			poolNumber;
	int				next;
	int				prev;
}					t_glob;

typedef struct		s_pool
{
	void			**pool;
	size_t			*totalSize;
	size_t			*usedSize;
	size_t			number;
}					t_pool;

typedef struct		s_metadata
{
	int				indexLastGlob;
	size_t			freeGlobSize;
	t_glob			map[GLOB_INITIAL_NUMBER];
}					t_metadata;

typedef struct		s_core
{
	t_pool			*pool;
	t_metadata		*meta;
	size_t			firstAllocatedSize;
	size_t			mapNumber;
}					t_core;

t_metadata			*new_meta_data(void);
t_core				*init_core_data(size_t size);
void				intern_alloc_new_pool(t_core *core, size_t size);
void				intern_alloc_new_map(t_core *core);
void				*alloc_request(size_t size);
void				*intern_user_alloc(size_t size, t_core *core);

#endif