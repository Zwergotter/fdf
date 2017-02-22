/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/22 12:05:38 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


void    rotate(double *one, double *two, t_env *env)
{
    one[0] = (one[0] * cos(env->rotation * 2 * M_PI / 360)) - (one[1] * sin(env->rotation * 2 * M_PI / 360));
    one[1] = (one[0] * sin(env->rotation * 2 * M_PI / 360)) + (one[1] * cos(env->rotation * 2 * M_PI / 360));
    two[0] = (two[0] * cos(env->rotation * 2 * M_PI / 360)) - (two[1] * sin(env->rotation * 2 * M_PI / 360));
    two[1] = (two[0] * sin(env->rotation * 2 * M_PI / 360)) + (two[1] * cos(env->rotation * 2 * M_PI / 360));
}

void draw(double *one, double *two, t_env *env)
{
    int start;
    double a;
    double b;

    if (one[0] == two[0] && one[1] == two[1])
        mlx_pixel_put(env->mlx, env->win, one[0] + env->move, one[1] + env->move, 00255555000);
    else if (fabs(one[1] - two[1]) <= fabs(one[0] - two[0]))
    {
        a = ((one[1] - two[1]) / (one[0] - two[0]));
        b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
        start = (one[0] < two[0] ? one[0] : two[0]) - 1;
        while (++start <= (one[0] < two[0] ? two[0] : one[0]))
            mlx_pixel_put(env->mlx, env->win, start + env->move, (a * start + b) + env->move, 00255555000);
    }
    else
    {
        a = ((one[1] - two[1]));
        b = ((one[0] * two[1] - one[1] * two[0]));
        start = (one[1] < two[1] ? one[1] : two[1]) - 1;
        while (++start <= (one[1] < two[1] ? two[1] : one[1]))
            mlx_pixel_put(env->mlx, env->win, ((start * (one[0] - two[0]) - b) / a) + env->move, start + env->move, 00255555000);
    }
}

void    draw_line(double *one, double *two, t_env *env)
{
    if (env->rotation * 2 * M_PI / 360)
        rotate(one, two, env);
    draw(one, two, env);
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
                one[0] = x * env->zoom;
                one[1] = (y - (ft_atoi(env->array_pos[y][x]) * env->depth)) * env->zoom;
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
    t_error error;

    error = MALLOC;
    if ((!(one = (double*)malloc(sizeof(double) * 2))) || (!(two = (double*)malloc(sizeof(double) * 2))))
        error_displayed(error);
    check_before_draw(env, one, two);
    return (1);
}
