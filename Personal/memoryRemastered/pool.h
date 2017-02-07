/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:58:15 by mlevieux          #+#    #+#             */
/*   Updated: 2017/02/07 18:41:28 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POOL_H
# define _POOL_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

# define GLOB_INITIAL_NUMBER 512
# define TRUE 1
# define FALSE 0

// [a-z_]+\t+\*?[a-z_]+\(.+\) (regex pour trouver les fonctions)

typedef	struct		s_glob
{
	void			*globAdress; // Adresse que le bloc concerne map actuellement : NULL si la memoire a cet emplacement est vide
	size_t			globSize; // Taille de la memoire mappee en octets
	size_t			poolNumber; // Numero de la pool mappee pas ce globule
	int				next;
	int				prev;
}					t_glob;

typedef struct		s_pool
{
	void			**pool; // Tableau de tableaux de void
	size_t			*totalSize; // Tableaux des tailles des tableaux de memoire
	size_t			*usedSize; // Tableaux des quantites de memoire utilisees dans les tableaux de memoire
	size_t			number; // Nombre de pools
}					t_pool;

typedef struct		s_metadata
{
	int				indexLastGlob; // Index du dernier globule dans la map
	int				*firstPoolIndex; // Tableau des index des premiers globules de chaque pool
	t_glob			*map; // Map
}					t_metadata;

typedef struct		s_core
{
	t_pool			*pool; // Pool de donnees
	t_metadata		*meta; // Mappage des pools
	size_t			firstAllocatedSize; // Taille du premier bloc alloue (donc taille a chaque fois)
	size_t			mapNumber; // Nombre de globules par map
}					t_core;

t_metadata			*new_meta_data(void);
t_core				*init_core_data(size_t size);
void				intern_alloc_new_pool(t_core *core, size_t size);
void				intern_alloc_new_map(t_core *core);
void				*alloc_request(size_t size, int code);
void				*intern_user_alloc(size_t size, t_core *core);
int					intern_get_free_adress(size_t size, t_core *core, int pool_number);
void				*intern_update_memory_map(t_core *core, size_t size, int pool_number, int free_adress);
void				dump_pool_memory(t_core *core);

// Functions to be used by user
void				init_memory(size_t size);
void				*new_memory(size_t size);
void				dump_memory();

#endif