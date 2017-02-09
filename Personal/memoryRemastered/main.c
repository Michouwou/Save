/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:58:09 by mlevieux          #+#    #+#             */
/*   Updated: 2017/02/09 16:39:06 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

int main(void)
{
	void	*space;

	init_memory((size_t)500);
	space = new_memory((size_t)20);
	ft_strcpy((char*)space, "helllooooooo\n");
	printf("LOL");
	printf("%s", (char*)space);
	dump_memory();
	printf("LOL");
	ft_strcpy((char*)new_memory(256), "blim blam bloum\n");
	dump_memory();
	space = new_memory(400);
	dump_memory();
	printf("LOL\n");
	ft_strcpy((char*)space, "MMMMAIIISS WWWWHHHHHAAAAATTTT?\?\?\?!!!!!\n");

	dump_memory();
	return (0);
}
