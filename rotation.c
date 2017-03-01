/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:20:31 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/24 14:20:36 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     color(int color1, int color2)
{
        if (color1 > 0 || color2 > 0)
            return (121248248); //bleu
        else
            return (198008000); //rouge
            
}

void	apply_rot(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 84) /////////////////////////////////////////////////keycode for up and 8
		{
			if (env->rot == R_MAX)
				env->rot = R_MINI;
			env->rot += ROT;
		}
	if (keycode == 91) /////////////////////////////////////////////////keycode for down and 2
		{
			if (env->rot == R_MINI)
				env->rot = R_MAX;
			env->rot -= ROT;
		}
	draw_map(env);
}
