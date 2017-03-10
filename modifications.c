/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:20:31 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/10 18:20:24 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modify_zoom(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 69)
		env->zoom += FDF_ZOOM;
	else
		env->zoom -= FDF_ZOOM;
	draw_map(env);
}

void	moving_map(t_env *env, int keycode)
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

void	changing_depth(t_env *env, int keycode)
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
	if (env->rot_x == FDF_R_MAX || env->rot_x == FDF_R_MINI)
		env->rot_x = (env->rot_x == FDF_R_MAX) ? FDF_R_MINI : FDF_R_MAX;
	if (env->rot_y == FDF_R_MAX || env->rot_y == FDF_R_MINI)
		env->rot_y = (env->rot_y == FDF_R_MAX) ? FDF_R_MINI : FDF_R_MAX;
	if (keycode == 84)
		env->rot_x += FDF_ROT;
	if (keycode == 91)
		env->rot_x -= FDF_ROT;
	if (keycode == 89)
		env->rot_y += FDF_ROT;
	if (keycode == 92)
		env->rot_y -= FDF_ROT;
	draw_map(env);
}
