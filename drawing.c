/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/10 17:59:28 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(double *one, double *two, t_env *env, int z, int z_bis)
{
	double begin;
	double a;
	double b;

	if (one[0] == two[0] && one[1] == two[1])
		mlx_pixel_put(env->mlx, env->win, one[0], one[1], color(env, z, z_bis));
	else if (fabs(one[1] - two[1]) <= fabs(one[0] - two[0]))
	{
		a = ((one[1] - two[1]) / (one[0] - two[0]));
		b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
		begin = (one[0] < two[0] ? one[0] : two[0]) - 1;
		while (++begin <= (one[0] < two[0] ? two[0] : one[0]))
			mlx_pixel_put(env->mlx, env->win, begin, (a * begin + b), color(env, z, z_bis));
	}
	else
	{
		a = ((one[1] - two[1]));
		b = ((one[0] * two[1] - one[1] * two[0]));
		begin = (one[1] < two[1] ? one[1] : two[1]) - 1;
		while (++begin <= (one[1] < two[1] ? two[1] : one[1]))
			mlx_pixel_put(env->mlx, env->win, ((begin * (one[0] - two[0]) - b) / a), begin, color(env, z, z_bis));
	}
}

void	draw_line(double *one, double *two, t_env *env, int z, int z_bis)
{
	double O[2];
	double T[2];

	O[0] = one[0];
	O[1] = one[1];
	T[0] = two[0];
	T[1] = two[1];
	O[0] = (O[0] * env->zoom) + env->mv_x;
	O[1] = ((O[1] - (z * env->depth)) * env->zoom) + env->mv_y;        
	T[0] = (T[0] * env->zoom) + env->mv_x;
	T[1] = ((T[1] - (z_bis * env->depth)) * env->zoom) + env->mv_y;
	draw(O, T, env, z, z_bis);
}

void	check_before_draw(t_env *env, double *one, double *two)
{
	double T[2];
	int x;
	int y;                                        

	y = -1;
	while (env->array_pos[++y])
	{
		one[0] = one[0] + sin(env->rot_y * 2 * M_PI / 360);
		one[1] = one[1] - cos(env->rot_y * 2 * M_PI / 360);
		two[0] = one[0];
		two[1] = one[1];
		x = -1;
		while (env->array_pos[y][++x])
		{
			two[0] = two[0] - sin(env->rot_x * 2 * M_PI / 360);
			two[1] = two[1] + cos(env->rot_x * 2 * M_PI / 360);
			T[0] = two[0] - sin(env->rot_x * 2 * M_PI / 360);
			T[1] = two[1] + cos(env->rot_x * 2 * M_PI / 360);
			if (env->array_pos[y][x + 1])
				draw_line(two, T, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y][x + 1]));
			T[0] = two[0] + sin(env->rot_y * 2 * M_PI / 360);
			T[1] = two[1] - cos(env->rot_y * 2 * M_PI / 360);
			if (env->array_pos[y + 1] && env->array_pos[y + 1][x])
				draw_line(two, T, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y + 1][x]));
		}
	}
}

int		draw_map(t_env *env)
{
	double one[2];
	double two[2];

	one[0] = 0;
	one[1] = 0;
	two[0] = 0;
	two[1] = 0;
	check_before_draw(env, one, two);
	return (1);
}
