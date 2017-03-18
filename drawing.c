/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 17:10:26 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(int x, int y, int color, t_env *env)
{
	if (x < 0 || y < 0)
		return ;
	if (x > env->win_x || y > env->win_y)
		return ;
	env->p_img = mlx_get_data_addr(env->img, &(env->bpp), &(env->s_line),
			&(env->ed));
	((int *)env->p_img)[x + y * env->s_line / 4] = color;
}

/*
** Draws all pixels between the two points by checking which absolute value
** of point is higher.
** Calls put_pixel for each of them.
*/

void		draw(double *one, double *two, t_env *env, int *z)
{
	double	begin;
	double	a;
	double	b;

	if (one[0] == two[0] && one[1] == two[1])
		put_pixel(one[0], one[1], color(env, z[0], z[1]), env);
	else if (fabs(one[1] - two[1]) <= fabs(one[0] - two[0]))
	{
		a = ((one[1] - two[1]) / (one[0] - two[0]));
		b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
		begin = (one[0] < two[0] ? one[0] : two[0]) - 1;
		while (++begin <= (one[0] < two[0] ? two[0] : one[0]))
			put_pixel(begin, (a * begin + b), color(env, z[0], z[1]), env);
	}
	else
	{
		a = ((one[1] - two[1]));
		b = ((one[0] * two[1] - one[1] * two[0]));
		begin = (one[1] < two[1] ? one[1] : two[1]) - 1;
		while (++begin <= (one[1] < two[1] ? two[1] : one[1]))
			put_pixel(((begin * (one[0] - two[0]) - b) / a), begin,
					color(env, z[0], z[1]), env);
	}
}

/*
** Applies height, depthm zoom and moves to both points, to their x[0] and y[1]
** coordinates.
** Then calls draw function.
*/

void		draw_line(t_coord *coord, double *points, t_env *env)
{
	double	one[2];
	double	two[2];

	one[0] = coord->two[0];
	one[1] = coord->two[1];
	two[0] = points[0];
	two[1] = points[1];
	one[0] = (one[0] * env->zoom) + env->mv_x;
	one[1] = ((one[1] - (coord->z[0] * env->depth)) * env->zoom) + env->mv_y;
	two[0] = (two[0] * env->zoom) + env->mv_x;
	two[1] = ((two[1] - (coord->z[1] * env->depth)) * env->zoom) + env->mv_y;
	draw(one, two, env, coord->z);
}

/*
** Set coordinates for second point either it exists on a column(1) or on a
** line(2).
** Applies rotations.
** Also sets values of height of first point and second point in coord->z.
** Calls draw_line with these variables as arguments.
*/

void		get_coord(t_env *env, t_coord *coord, int i)
{
	double	points[2];

	if (i == 1)
	{
		points[0] = coord->two[0] - sin(env->rot_x * 2 * M_PI / 360);
		points[1] = coord->two[1] + cos(env->rot_x * 2 * M_PI / 360);
		coord->z[0] = ft_atoi(env->array_pos[coord->y][coord->x]);
		coord->z[1] = ft_atoi(env->array_pos[coord->y][coord->x + 1]);
	}
	if (i == 2)
	{
		points[0] = coord->two[0] + sin(env->rot_y * 2 * M_PI / 360);
		points[1] = coord->two[1] - cos(env->rot_y * 2 * M_PI / 360);
		coord->z[0] = ft_atoi(env->array_pos[coord->y][coord->x]);
		coord->z[1] = ft_atoi(env->array_pos[coord->y + 1][coord->x]);
	}
	draw_line(coord, points, env);
}

/*
** Function called by draw_map in file fdf.c. It checks if a coordinate exists
** before calling get_coord.
** Coordinates one are saved in order to keep these values.
*/

void		check_before_draw(t_env *env, t_coord *coord)
{
	coord->y = -1;
	while (env->array_pos[++coord->y])
	{
		coord->one[0] = coord->one[0] + sin(env->rot_y * 2 * M_PI / 360);
		coord->one[1] = coord->one[1] - cos(env->rot_y * 2 * M_PI / 360);
		coord->two[0] = coord->one[0];
		coord->two[1] = coord->one[1];
		coord->x = -1;
		while (env->array_pos[coord->y][++coord->x])
		{
			coord->two[0] = coord->two[0] - sin(env->rot_x * 2 * M_PI / 360);
			coord->two[1] = coord->two[1] + cos(env->rot_x * 2 * M_PI / 360);
			if (env->array_pos[coord->y][coord->x + 1])
				get_coord(env, coord, 1);
			if (env->array_pos[coord->y + 1]
					&& env->array_pos[coord->y + 1][coord->x])
				get_coord(env, coord, 2);
		}
	}
}
