/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:17:18 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 17:13:26 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed(int key, t_env *env)
{
	if (key == 84 || key == 91 || key == 92 || key == 89)
		apply_rot(env, key);
	if ((key == 78 && env->zoom > FDF_Z_MINI) || (key == 69 && env->zoom <
				FDF_Z_MAX))
		modify_zoom(env, key);
	if (key >= 123 && key <= 126)
		moving_map(env, key);
	if ((key == 86 && env->depth > FDF_D_MINI) || (key == 88 && env->depth <
				FDF_D_MAX))
		changing_depth(env, key);
	if (key == 18 || key == 29)
	{
		env->key = key;
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_image(env->mlx, env->img);
		env->img = mlx_new_image(env->mlx, env->win_x * 1.5, env->win_y * 1.5);
		env->p_img = mlx_get_data_addr(env->img, &env->bpp, &(env->s_line),
				&(env->ed));
		draw_map(env);
	}
	if (key == 53)
		exit(0);
	return (1);
}
