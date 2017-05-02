/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:53:20 by edeveze           #+#    #+#             */
/*   Updated: 2017/04/25 23:04:08 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Prints controls on window to know which key changes what.
*/

void	printcontrol(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 20, 20, 0xf2f2f2,
		"ROTATION: (PAV NUM) 4 / 6 / 8 / 2");
	mlx_string_put(env->mlx, env->win, 20, 40, 0xf2f2f2,
		"TRANSLATION: ARROWS");
	mlx_string_put(env->mlx, env->win, 20, 60, 0xf2f2f2,
		"DEEPNESS : (PAV NUM) 7 / 9");
	mlx_string_put(env->mlx, env->win, 20, 80, 0xf2f2f2,
		"ZOOM : (PAV NUM) - / +");
	mlx_string_put(env->mlx, env->win, 20, 100, 0xf2f2f2,
		"COLORS : 0 / 1 / 2 / 3");
	mlx_string_put(env->mlx, env->win, 20, 120, 0xf2f2f2,
		"EXIT: ESC");
}
