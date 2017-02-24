/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/16 18:20:35 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	}
	else
	{
		error = USAGE;
		error_displayed(error);
	}
	return (0);
}
