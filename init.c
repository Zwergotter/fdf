/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:56:46 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/16 16:57:20 by edeveze          ###   ########.fr       */
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
	env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, FDF_NAME_WIN);
    env->img = mlx_new_image(env->mlx, env->win_x * 1.5, env->win_y * 1.5);
    env->p_img = mlx_get_data_addr(env->img, &env->bpp, &(env->s_line), &(env->ed));
	if (!(env->array_pos = malloc(sizeof(char **) * env->len + 1)))
		error_displayed(error);
	env->array_pos[env->len] = NULL;
	init_array(map, env);
}
