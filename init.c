/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:27:01 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/09 13:29:58 by edeveze          ###   ########.fr       */
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

	if ((fd = open(map, O_RDONLY)) < 0)
        exit (0);
	env->win_x = 1200;
	env->win_y = 800;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "fdf");
	env->len = map_length(fd);
	env->zoom = 20;
    env->move = 200;
	env->depth = 0.1;
	printf("in init_env - env address is %p\n", env);
	printf("in init_env - env->mlx address is %p\n", env->mlx);
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;

		fd = open(file, O_RDONLY);
		if (!(array_pos = read_file(array_pos, fd)))
            exit (0);
		close(fd);
}

void init_everything(t_env *env, char *map)
{
    init_env(env, map);
    if (!(env->array_pos = (char***)malloc(sizeof(char) * env->len + 1)))
        exit (0);
    env->array_pos[env->len] = NULL;
    init_array(env->array_pos, map);
}
