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

/*
** Reacts to some keys when they're pressed and reacts by calling a function
** in modifications.c file or just exit when esc is pressed for an example.
*/

int	key_pressed(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else
	{
		new_image(env);
		if (key == 84 || key == 91 || key == 86 || key == 88)
			apply_rot(env, key);
		if ((key == 78 && env->zoom > FDF_Z_MINI) || (key == 69 && env->zoom <
					FDF_Z_MAX))
			modify_zoom(env, key);
		if (key >= 123 && key <= 126)
			moving_map(env, key);
		if ((key == 89 && env->depth > FDF_D_MINI) || (key == 92 && env->depth <
					FDF_D_MAX))
			changing_depth(env, key);
		if (key == 18 || key == 29)
			env->key = key;
		draw_map(env);
	}
	return (1);
}
