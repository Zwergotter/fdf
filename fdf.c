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

int     map_length(int fd)
{
    char buf[1];
    int i;

    i = 0;
    while (read(fd, buf, 1))
    {
        if (buf[0] == '\n')
            i++;
    }
    if (buf[0] != '\n')
        i++;
    return (i);
}

void init_env(t_env *env, char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	env->x = 50;
	env->y = 50;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, LENGTH, "fdf");
	env->len = map_length(fd);
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;

		fd = open(file, O_RDONLY);
		array_pos = read_file(array_pos, fd);
		close(fd);
}

int	main(int ac, char **av)
{
	t_env *env;
	char ***array_pos;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			return (-1);
		init_env(env, av[1]);
		if (!(array_pos = (char***)malloc(sizeof(char) * env->len + 1)))
			return (-1);
		array_pos[env->len] = NULL;
		init_array(array_pos, av[1]);
		while (env->y++ < 150)
			mlx_pixel_put(env->mlx, env->win, env->x, env->y, 00255000000);
		mlx_loop(env->mlx);	
	}
	return (0);
}
