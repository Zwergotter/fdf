/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/24 22:15:08 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	x = 50;
	y = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx window");
	while (y++ < 150)
		mlx_pixel_put(mlx, win, x, y, 00255000000);
	mlx_loop(mlx);
	return (0);
}
