/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:27:01 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/10 18:17:23 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_length(int fd)
{
	char	buf[1];
	int		i;

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

void	init_env(t_env *env, char *map)
{
	int		fd;
	t_error	error;

	error = ARGUMENT;
	if ((fd = open(map, O_RDONLY)) < 0)
		error_displayed(error);
    env->len = map_length(fd);
	env->win_x = (env->len * 50 > 1280) ? 1280 : env->len * 50;
	env->win_y = (env->len * 25 > 1024) ? 1024 : env->len * 25;
    if ( env->len * 50 < 1280 && env->len * 25 < 1024)
        {
            env->win_x = (env->len * 50 < 640) ? 640 : env->len * 50;
            env->win_y = (env->len * 25 < 480) ? 480 : env->len * 25;
        }
    env->zoom = env->win_x / (env->len * 1.75);
	env->mv_x = env->win_x / 10;
	env->mv_y = env->win_y / 3;
	env->rot_x = 250;
	env->rot_y = 150;
	env->depth = env->zoom / 50;
	env->key = 0;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, FDF_NAME_WIN);
	close(fd);
}

void	init_array(char *file, t_env *env)
{
	int		fd;
	t_error error;

	error = ARGUMENT;
	fd = open(file, O_RDONLY);
	if (!(env->array_pos = read_file(env->array_pos, fd)))
		error_displayed(error);
	close(fd);
}

void	init_everything(t_env *env, char *map)
{
	t_error error;

	error = MALLOC;
	init_env(env, map);
	if (!(env->array_pos = malloc(sizeof(char **) * env->len + 1)))
		error_displayed(error);
	env->array_pos[env->len] = NULL;
	init_array(map, env);
}
