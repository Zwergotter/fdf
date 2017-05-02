/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:56:46 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/18 01:15:39 by edeveze          ###   ########.fr       */
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

/*
** Set all environment's variables.
*/

void	init_env(t_env *env, char *map)
{
	int		fd;
	t_error	error;

	error = ARGUMENT;
	if ((fd = open(map, O_RDONLY)) < 0)
		error_displayed(error);
	env->len = map_length(fd);
	env->win_x = env->len * 70;
	env->win_y = env->len * 56;
	env->win_x = (env->win_x > 1600 ? 1600 : env->win_x);
	env->win_y = (env->win_y > 1280 ? 1280 : env->win_y);
	env->zoom = (env->win_x == 1600) ? env->win_x / (env->len * 2) :
		env->win_y / (env->len * 2);
	env->mv_x = (env->win_x < 1600) ? 0 : env->win_y / 15;
	env->mv_y = (env->win_y * 6) / 10;
	env->rot_x = 240;
	env->rot_y = 120;
	env->depth = 0;
	env->key = 0;
	close(fd);
}

/*
** Calls read_file from file parsing.c in order to acces to all coordinates.
** Calls also depth in order to have a better image at the end.
*/

void	init_array(char *file, t_env *env)
{
	int		fd;
	t_error error;

	error = ARGUMENT;
	fd = open(file, O_RDONLY);
	if (!(env->array_pos = read_file(env->array_pos, fd)))
		error_displayed(error);
	depth(env);
	close(fd);
}

/*
** Takes as argument env struct and file that contains map.
** Initializes first datas in env.
** Then puts all map's data in an array that will contains all coordinates.
*/

void	init_everything(t_env *env, char *map)
{
	t_error error;

	error = MALLOC;
	init_env(env, map);
	env->coord_x = 0;
	env->coord_y = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, FDF_NAME_WIN);
	env->img = mlx_new_image(env->mlx, env->win_x * 1.5, env->win_y * 1.5);
	env->p_img = mlx_get_data_addr(env->img, &env->bpp, &(env->s_line),
			&(env->ed));
	if (!(env->array_pos = malloc(sizeof(char **) * env->len + 1)))
		error_displayed(error);
	env->array_pos[env->len] = NULL;
	init_array(map, env);
}
