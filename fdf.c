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

void init_env(t_env *env)
{
	env->x = 50;
	env->y = 50;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, LENGTH, "fdf");
}

void init_array(t_pos **array_pos, char **av)
{
		int		fd;

		fd = open(av[1], O_RDONLY);
		array_pos = read_file(fd);
		close(fd);
}

int	main(int ac, char **av)
{
	t_env *env;
	t_pos **array_pos;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))) ||
			!(array_pos = (t_pos**)malloc(sizeof(t_pos))))
			return (-1);
		init_array(array_pos, &av[1]);
		init_env(env);
		while (env->y++ < 150)
			mlx_pixel_put(env->mlx, env->win, env->x, env->y, 00255000000);
		mlx_loop(env->mlx);	
	}
	return (0);
}
