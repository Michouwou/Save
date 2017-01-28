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


	printf("Initialisation de la structure...\n");
	pool = init_oPool((size_t)8001, 5);

	
	printf("Allocation des pointeurs...\n");
	
	void *ptr1 = oPool_alloc(pool, (size_t)2000);
	printf("Pointeur 1 OK...\n");

	void *ptr2 = oPool_alloc(pool, (size_t)2000);
	printf("Pointeur 2 OK...\n");
	
	void *ptr3 = oPool_alloc(pool, (size_t)2000);
	printf("Pointeur 3 OK...\n");
	
	void *ptr4 = oPool_alloc(pool, (size_t)2000);
	printf("Pointeur 4 OK...\n");


	char *bigChaine = (char*)ptr1;
	int	*intTab = (int*)ptr2;
	float *floatTab = (float*)ptr3;


	printf("Deletion du chunk 4 de la structure...\n");
	del_oPool_chunk(pool, 4);


	printf("Accession a l'index 3 de la structure...\n");
	ptr4 = oPool_indexBaseAcces(pool, 3);


	printf("Liberation complete de la memoire...\n");
	free_oPool(pool);
	return (0);
}
