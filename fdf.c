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

int		draw_map(t_env *env)
{
	t_coord	*coord;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		error_displayed(MALLOC);
	coord->one[0] = 0;
	coord->one[1] = 0;
	coord->two[0] = 0;
	coord->two[1] = 0;
	check_before_draw(env, coord);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}

void	loop(t_env *env)
{
	mlx_key_hook(env->win, key_pressed, env);
	mlx_expose_hook(env->win, draw_map, env);
	mlx_loop(env->mlx);
}

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
