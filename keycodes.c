/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:17:18 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/24 14:17:20 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

void modify_zoom(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 24 || keycode == 69)
		env->zoom += ZOOM;
	else
		env->zoom -= ZOOM;
	draw_map(env);
}

void moving_map(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 123)
		env->mv_x -= MOVING;
	if (keycode == 124)
		env->mv_x += MOVING;
	if (keycode == 125)
		env->mv_y += MOVING;
	if (keycode == 126)
		env->mv_y -= MOVING;
	draw_map(env);
}

void changing_depth(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 1)
		env->depth -= DEPTH;
	else
		env->depth += DEPTH;
	draw_map(env);
}

int	key_pressed(int keycode, t_env *env)
{
	if (keycode == 84 || keycode == 91)
		apply_rot(env, keycode);
	if (((keycode == 27 || keycode == 78) && env->zoom > Z_MINI) || ((keycode == 24 || keycode == 69) && env->zoom < Z_MAX))
		modify_zoom(env, keycode);
	if (keycode >= 123 && keycode <= 126)
		moving_map(env, keycode);
	if ((keycode == 1 && env->depth > D_MINI) || (keycode == 2 && env->depth < D_MAX))
		changing_depth(env, keycode);
	if (keycode == 53)
		exit (0);
	printf("Code of key pressed is %d\n", keycode);
	return (1);
}
