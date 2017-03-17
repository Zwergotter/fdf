/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 15:50:54 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, int color, t_env *env)
{
	if (x < 0 || y < 0)
		return ;
	if(x > env->win_x || y > env->win_y)
		return ;
	env->p_img = mlx_get_data_addr(env->img, &(env->bpp), &(env->s_line),
	&(env->ed));
	((int *)env->p_img)[x + y * env->s_line / 4] = color;
}

void	draw(double *one, double *two, t_env *env, int *z)
{
	double begin;
	double a;
	double b;

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

void	draw_line(t_coord *coord, double *t, t_env *env)
{
	double O[2];
	double T[2];

	O[0] = coord->two[0];
	O[1] = coord->two[1];
	T[0] = t[0];
	T[1] = t[1];
	O[0] = (O[0] * env->zoom) + env->mv_x;
	O[1] = ((O[1] - (coord->z[0] * env->depth)) * env->zoom) + env->mv_y;        
	T[0] = (T[0] * env->zoom) + env->mv_x;
	T[1] = ((T[1] - (coord->z[1] * env->depth)) * env->zoom) + env->mv_y;
	draw(O, T, env, coord->z);
}

void get_coord(t_env *env, t_coord *coord, double *T, int i)
{
	if (i == 1)
	{
		T[0] = coord->two[0] - sin(env->rot_x * 2 * M_PI / 360);
		T[1] = coord->two[1] + cos(env->rot_x * 2 * M_PI / 360);
		coord->z[0] = ft_atoi(env->array_pos[coord->y][coord->x]);
		coord->z[1] = ft_atoi(env->array_pos[coord->y][coord->x + 1]);
	}
		
	if (i == 2)
	{
		T[0] = coord->two[0] + sin(env->rot_y * 2 * M_PI / 360);
		T[1] = coord->two[1] - cos(env->rot_y * 2 * M_PI / 360);
		coord->z[0] = ft_atoi(env->array_pos[coord->y][coord->x]);
		coord->z[1] = ft_atoi(env->array_pos[coord->y + 1][coord->x]);
	}
	draw_line(coord, T, env);
}

void	check_before_draw(t_env *env, t_coord *coord)
{
	double T[2];                                

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
				get_coord(env, coord, T, 1);
			if (env->array_pos[coord->y + 1]
				&& env->array_pos[coord->y + 1][coord->x])
				get_coord(env, coord, T, 2);
		}
	}
}

int		draw_map(t_env *env)
{
	t_coord	*coord;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		error_displayed(MALLOC); 	
	coord->one[0] = 0;
	coord->one[1] = 0;
	coord->two[0] = 0;
	coord->two[1] = 0;
	check_before_draw(env, coord);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}