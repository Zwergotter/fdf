/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/08 15:38:51 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void    draw_line(double *one, double *two, t_env *env)
{
    int start;
    double a;
    double b;

    if (one[0] == two[0] && one[1] == two[1])
        mlx_pixel_put(env->mlx, env->win, one[0], one[1], 00255555000);
    else if (fabs(one[1] - two[1]) <= fabs(one[0] - two[0]))
    {
        a = ((one[1] - two[1]) / (one[0] - two[0]));
        b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
        start = (one[0] < two[0] ? one[0] : two[0]) - 1;
        while (++start <= (one[0] < two[0] ? two[0] : one[0]))
            mlx_pixel_put(env->mlx, env->win, start, (a * start + b), 00255555000);
    }
    else
    {
        a = ((one[1] - two[1]));
        b = ((one[0] * two[1] - one[1] * two[0]));
        start = (one[1] < two[1] ? one[1] : two[1]) - 1;
        while (++start <= (one[1] < two[1] ? two[1] : one[1]))
            mlx_pixel_put(env->mlx, env->win, (start * (one[0] - two[0]) - b) / a, start, 00255555000);
    }
}

void check_before_draw(t_env *env, double *one, double *two)
{
    int x;
    int y;

    y = -1;
    while (env->array_pos[++y])
    {
        x = -1;
        while (env->array_pos[y][++x] != '\0')
        {
            one[0] = x * env->zoom;
            one[1] = (y - (ft_atoi(env->array_pos[y][x]) * env->depth)) * env->zoom;
            if (env->array_pos[y][x + 1])
            {
                two[0] = (x + 1) * env->zoom;
                two[1] = (y - ft_atoi(env->array_pos[y][x + 1]) * env->depth) * env->zoom;
                draw_line(one, two, env);
            }
            if (y + 1 < env->len && env->array_pos[y + 1][x])
            {
                two[0] = x * env->zoom;
                two[1] = (y + 1 - (ft_atoi(env->array_pos[y + 1][x]) * env->depth)) * env->zoom;
                draw_line(one, two, env);
            }
        }
    }
}

int draw_map(t_env *env)
{
    double *one = NULL;
    double *two = NULL;
    
    if ((!(one = (double*)malloc(sizeof(double) * 2))) || (!(two = (double*)malloc(sizeof(double) * 2))))
        return (0);
    check_before_draw(env, one, two);
    return (1);
}
