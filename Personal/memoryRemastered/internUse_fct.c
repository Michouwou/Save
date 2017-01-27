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

