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

int	key_pressed(int key, t_env *env)
{
	if (key == 84 || key == 91)
		apply_rot(env, key);
	if ((key == 78 && env->zoom > FDF_Z_MINI) || (key == 69 && env->zoom < FDF_Z_MAX))
		modify_zoom(env, key);
	if (key >= 123 && key <= 126)
		moving_map(env, key);
	if ((key == 86 && env->depth > FDF_D_MINI) || (key == 88 && env->depth < FDF_D_MAX))
		changing_depth(env, key);
	if (key == 53)
		exit (0);
	printf("Code of key pressed is %d\n", key);
	return (1);
}
