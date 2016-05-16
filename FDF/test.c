/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:49:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/16 18:00:01 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void	*ptr;
	void	*window;

	ptr = mlx_init();
	window = mlx_new_window(ptr, 500, 500, "Hellooooo");
	for (int i = 0 ; i < 50 ; i++)
		for (int j = 0 ; j < 50 ; j++)
			mlx_pixel_put(ptr, window, j, i, 0x0FFFFFF);
	mlx_loop(ptr);
	return (0);
}
