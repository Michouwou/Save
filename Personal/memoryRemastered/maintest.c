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
	t_oPool	*pool;
	char	*ptr, *ptr2;
	size_t	sizes[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 0};

	pool = init_oPool((size_t)200, 5);
	ptr = (char*)oPool_alloc(pool, (size_t)30);
	printf("ptr %p\n", ptr);
	ft_strcpy(ptr, "Salut je suis nulle");
	printf("|%s|\n", ptr);

	ptr2 = (char*)oPool_alloc(pool, (size_t)30);
	ft_strcpy(ptr2, "plop plop plop plop plop");
	printf("|%s|\n", ptr2);

	for (int i = 0 ; ptr[i] || i < 29 ; i++)
	{
		if (!ptr[i])
			ptr[i] = 'a';
	}
	printf("|%s|\n", ptr);
	del_oPool_chunk(pool, 0);
	printf("|%s|\n", ptr);
	ptr = oPool_alloc(pool, 20);
	ptr2 = oPool_alloc(pool, 5);
	printf("|%p|, |%p|\n", ptr, ptr2);
	return (0);
}
