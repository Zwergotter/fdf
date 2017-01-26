/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/25 19:26:39 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		read_file(fd);
		x = 50;
		y = 50;
		mlx = mlx_init();
		win = mlx_new_window(mlx, 400, 400, "mlx window");
		while (y++ < 150)
			mlx_pixel_put(mlx, win, x, y, 00255000000);
		mlx_loop(mlx);
	}
	return (0);
}
