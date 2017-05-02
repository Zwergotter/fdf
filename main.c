/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 17:11:17 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Sets coordinates we will need in order to draw map to zero.
** Calls function check_before_draw in file drawing.c.
** Then puts image of drawn map to window.
*/

int		draw_map(t_env *env)
{
	t_coord	*coord;
	t_error	error;

	error = MALLOC;
	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		error_displayed(error);
	coord->one[0] = env->coord_x;
	coord->one[1] = env->coord_y;
	coord->two[0] = 0;
	coord->two[1] = 0;
	check_before_draw(env, coord);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	printcontrol(env);
	return (1);
}

/*
** Calls key_hook to verify if one key was pressed and then calls function
** key_pressed in keycodes.c file.
** Then calls expose hook, calling itself draw_map.
** Finally mlx_loop is the last function which will wait for an event.
*/

void	loop(t_env *env)
{
	mlx_key_hook(env->win, key_pressed, env);
	mlx_expose_hook(env->win, draw_map, env);
	mlx_loop(env->mlx);
}

/*
** Verifies if number of arguments is one and then procedes by initializing
** all data, calling function init_everything available in file init.c.
** Then calls function loop to display them.
*/

int		main(int ac, char **av)
{
	t_env	*env;
	t_error error;

	error = MALLOC;
	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			error_displayed(error);
		init_everything(env, av[1]);
		loop(env);
	}
	else
	{
		error = USAGE;
		error_displayed(error);
	}
	return (0);
}
