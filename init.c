/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:27:01 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/22 13:44:56 by cosi             ###   ########.fr       */
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
    t_error error;

    error = ARGUMENT;
	if ((fd = open(map, O_RDONLY)) < 0)
        error_displayed(error);
	env->win_x = 1200;
	env->win_y = 800;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "fdf");
	env->len = map_length(fd);
	env->zoom = 10;
    env->move = 100;
    env->rotation = 0;
	env->depth = 0.2;
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;
        t_error error;

        error = ARGUMENT;
		fd = open(file, O_RDONLY);
		if (!(array_pos = read_file(array_pos, fd)))
            error_displayed(error);
		close(fd);
}

void init_everything(t_env *env, char *map)
{
    t_error error;

    error = MALLOC;
    init_env(env, map);
    if (!(env->array_pos = malloc(sizeof(char **) * env->len + 1)))
        error_displayed(error);
    env->array_pos[env->len] = NULL;
    init_array(env->array_pos, map);
}
