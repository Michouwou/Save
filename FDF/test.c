/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:49:27 by mlevieux          #+#    #+#             */
/*   Updated: 2016/05/19 11:36:37 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

int main()
{
	t_mlx	*ptr;
	int		p1[2] = {150, 50};
	int		p2[2] = {200, 280};

	ptr = (t_mlx*)malloc(sizeof(t_mlx));
	ptr->core = mlx_init();
	ptr->win = mlx_new_window(ptr->core, 1000, 1000, "Hellooooo");
	ft_draw_line(p1, p2, ptr);
	mlx_loop(ptr->core);
	return (0);
}
