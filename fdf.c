/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/08 15:12:23 by cosi             ###   ########.fr       */
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

/*void init_everything(t_env *env, char *map, )*/

void init_env(t_env *env, char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	env->win_x = 1200;
	env->win_y = 800;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "fdf");
	env->len = map_length(fd);
	env->zoom = 10;
	env->depth = 0.1;
	printf("in init_env - env address is %p\n", env);
	printf("in init_env - env->mlx address is %p\n", env->mlx);
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;

		fd = open(file, O_RDONLY);
		array_pos = read_file(array_pos, fd);
		close(fd);
}

int	key_pressed(int keycode, t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 53)
		exit (0);
	printf("Code of key pressed is %d\n", keycode);
	return (1);
}

void	loop(t_env *env)
{
	mlx_key_hook(env->win, key_pressed, env);
	mlx_expose_hook(env->win, draw_map, env);
	mlx_loop(env->mlx);
}

int	main(int ac, char **av)
{
	t_env *env;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			return (-1);
		init_env(env, av[1]);
		if (!(env->array_pos = (char***)malloc(sizeof(char) * env->len + 1)))
			return (-1);
		env->array_pos[env->len] = NULL;
		init_array(env->array_pos, av[1]);
		loop(env);
		printf("no segfault4\n");
	}
	return (0);
}
