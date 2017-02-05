/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 16:58:09 by mlevieux          #+#    #+#             */
/*   Updated: 2017/02/05 17:30:41 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pool.h>

int main(void)
{
	void	*space;

	space = alloc_request((size_t)20, 1);
	ft_strcpy((char*)space, "helllooooooo\n");
	printf("%s", (char*)space);
	alloc_request(0, 2);
	ft_strcpy((char*)alloc_request(256, 1), "blim blam bloum\n");
	alloc_request(0, 2);
	return (0);
}
