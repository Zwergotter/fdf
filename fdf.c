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
	env->x = 600;
	env->y = 600;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, LENGTH, "fdf");
	env->len = map_length(fd);
	env->zoom = 15;
	env->depth = 0.1;
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;

		fd = open(file, O_RDONLY);
		array_pos = read_file(array_pos, fd);
		close(fd);
}

int	key_pressed(int keycode)
{
	if (keycode == 53)
		exit (0);
	printf("Code of key pressed is %d\n", keycode);
	return (1);
}

int	main(int ac, char **av)
{
	t_env *env;
	t_max *coord;
	char ***array_pos;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			return (-1);
		init_env(env, av[1]);
		if (!(array_pos = (char***)malloc(sizeof(char) * env->len + 1)) || !(coord = (t_max*)malloc(sizeof(t_max))))
			return (-1);
		array_pos[env->len] = NULL;
		init_array(array_pos, av[1]);
		max_coord(array_pos, coord);
		printf("higher x, y min_heigth and max_heigth are %d, %d, %d, %d\n", coord->max_x, coord->max_y, coord->min_heigth, coord->max_heigth);
		/*draw_line(first, second, env);
		*/draw_map(array_pos, env);
		mlx_key_hook(env->win, key_pressed, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
