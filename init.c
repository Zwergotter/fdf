/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:27:01 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/23 14:31:16 by cosi             ###   ########.fr       */
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

void max_positions(t_env *env)
{
   int x;
   int y;

    y = -1;
    while (env->array_pos[++y])
    {
        x = -1;
        while (env->array_pos[y][++x] != '\0')
        {
            if (abs(x) > env->max_x)
                env->max_x = abs(x);
            if (abs(y - (ft_atoi(env->array_pos[y][x])) > env->max_y))
                env->max_y = abs(y - (ft_atoi(env->array_pos[y][x])));
            if (y - (ft_atoi(env->array_pos[y][x])) < env->max_y)
                env->min_y = y - (ft_atoi(env->array_pos[y][x]));
        }
    }
}

void init_env(t_env *env, char *map)
{
	int fd;
    t_error error;

    error = ARGUMENT;
	if ((fd = open(map, O_RDONLY)) < 0)
        error_displayed(error);
    env->max_x = 0;
    env->min_y = 0;
    env->max_y = 0;
	env->win_x = 1200;
	env->win_y = 800;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, FDF_NAME_WIN);
	env->len = map_length(fd);
	env->zoom = 10;
    env->mv_x = 50;
    env->mv_y = 50;
    env->rot_x = 270;
    env->rot_y = 190;
	env->depth = 0.2;
	close(fd);
}

void init_array(char *file, t_env *env)
{
		int		fd;
        t_error error;

        error = ARGUMENT;
		fd = open(file, O_RDONLY);
		if (!(env->array_pos = read_file(env->array_pos, fd)))
            error_displayed(error);
		close(fd);
        max_positions(env);
}

void init_everything(t_env *env, char *map)
{
    t_error error;

    error = MALLOC;
    init_env(env, map);
    if (!(env->array_pos = malloc(sizeof(char **) * env->len + 1)))
        error_displayed(error);
    env->array_pos[env->len] = NULL;
    init_array(map, env);
}
