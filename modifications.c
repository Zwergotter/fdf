/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
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

void modify_zoom(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 69)
		env->zoom += FDF_ZOOM;
	else
		env->zoom -= FDF_ZOOM;
	draw_map(env);
}

void moving_map(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 123)
		env->mv_x -= FDF_MOVING;
	if (keycode == 124)
		env->mv_x += FDF_MOVING;
	if (keycode == 125)
		env->mv_y += FDF_MOVING;
	if (keycode == 126)
		env->mv_y -= FDF_MOVING;
	draw_map(env);
}

void changing_depth(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 86)
		env->depth -= FDF_DEPTH;
	else
		env->depth += FDF_DEPTH;
	draw_map(env);
}

void	apply_rot(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 84)
		{
			if (env->rot == FDF_R_MAX)
				env->rot = FDF_R_MINI;
			env->rot += FDF_ROT;
		}
	if (keycode == 91)
		{
			if (env->rot == FDF_R_MINI)
				env->rot = FDF_R_MAX;
			env->rot -= FDF_ROT;
		}
	draw_map(env);
}
