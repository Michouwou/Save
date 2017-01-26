/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:33:26 by mlevieux          #+#    #+#             */
/*   Updated: 2017/01/26 17:59:43 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pool.h"
#include <stdio.h>

int main(void)
{
	t_pool	*pool;
	char	**ptr;
	size_t	sizes[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 0};

	pool = new_pool((size_t)200);
	ptr = (char**)pool_arrayAlloc(pool, sizes);
	for (int i = 0; i < 9; i++)
	   ptr[i] = ft_strdup("plop");
	for (int i= 0; i < 9; i++)
		printf("|%s|\n", ptr[i]);	
	return (0);
}
