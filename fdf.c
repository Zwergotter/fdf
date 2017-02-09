/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/09 16:49:52 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	t_error error;

	error = MALLOC;
	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			error_displayed(error);
        init_everything(env, av[1]);
		loop(env);
		printf("no segfault4\n");
	}
	else
	{
		error = USAGE;
		error_displayed(error);
	}
	return (0);
}
