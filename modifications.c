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

/*
** All next functions will applies the modification it supposes to,
** depends on which key is pressed and finally calls draw_map in main.c.
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
