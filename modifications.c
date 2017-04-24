/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:20:31 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 17:14:41 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_image(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->win_x * 1.5, env->win_y * 1.5);
	env->p_img = mlx_get_data_addr(env->img, &env->bpp, &(env->s_line),
			&(env->ed));
}

/*
** All next functions will firstly calls new_image in order to clear window,
** destroy image and then set a new one. Like this we will be able to draw a
** cleaned image.
** Then it does the modification it supposes to do depends on which key is 
** presed and finally calls draw_map in fdf.c file with the new value.
*/

void	modify_zoom(t_env *env, int keycode)
{
	if (keycode == 69)
		env->zoom += FDF_ZOOM;
	else
		env->zoom -= FDF_ZOOM;
}

void	moving_map(t_env *env, int keycode)
{
	if (keycode == 123)
		env->mv_x -= FDF_MOVING;
	if (keycode == 124)
		env->mv_x += FDF_MOVING;
	if (keycode == 125)
		env->mv_y += FDF_MOVING;
	if (keycode == 126)
		env->mv_y -= FDF_MOVING;
}

void	changing_depth(t_env *env, int keycode)
{
	if (keycode == 92)
		env->depth -= FDF_DEPTH;
	else
		env->depth += FDF_DEPTH;
}

void	apply_rot(t_env *env, int keycode)
{
	if (env->rot_x == FDF_R_MAX || env->rot_x == FDF_R_MINI)
		env->rot_x = (env->rot_x == FDF_R_MAX) ? FDF_R_MINI : FDF_R_MAX;
	if (env->rot_y == FDF_R_MAX || env->rot_y == FDF_R_MINI)
		env->rot_y = (env->rot_y == FDF_R_MAX) ? FDF_R_MINI : FDF_R_MAX;
	if (keycode == 88)
		env->rot_x += FDF_ROT;
	if (keycode == 86)
		env->rot_x -= FDF_ROT;
	if (keycode == 84)
		env->rot_y += FDF_ROT;
	if (keycode == 91)
		env->rot_y -= FDF_ROT;
}
