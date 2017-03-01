/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/24 14:18:23 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int     color(int color1, int color2)
{
        if (color1 > 0 || color2 > 0)
            return (121248248); //bleu
        else
            return (198008000); //rouge
            
}

void    rotate(double *one, double *two, t_env *env)
{
    one[0] = (one[0] * cos(env->rot * 2 * M_PI / 360)) - (one[1] * sin(env->rot * 2 * M_PI / 360));
    one[1] = (one[0] * sin(env->rot * 2 * M_PI / 360)) + (one[1] * cos(env->rot * 2 * M_PI / 360));
    two[0] = (two[0] * cos(env->rot * 2 * M_PI / 360)) - (two[1] * sin(env->rot * 2 * M_PI / 360));
    two[1] = (two[0] * sin(env->rot * 2 * M_PI / 360)) + (two[1] * cos(env->rot * 2 * M_PI / 360));
}

void    draw(double *one, double *two, t_env *env, int z, int z_bis)
{
    int begin;
    double a;
    double b;

    if (one[0] == two[0] && one[1] == two[1])
        mlx_pixel_put(env->mlx, env->win, one[0] + env->mv, one[1] + env->mv, color(z, z_bis));
    else if (fabs(one[1] - two[1]) <= fabs(one[0] - two[0]))
    {
        a = ((one[1] - two[1]) / (one[0] - two[0]));
        b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
        begin = (one[0] < two[0] ? one[0] : two[0]) - 1;
        while (++begin <= (one[0] < two[0] ? two[0] : one[0]))
            mlx_pixel_put(env->mlx, env->win, begin + env->mv, (a * begin + b) + env->mv, color(z, z_bis));
    }
    else
    {
        a = ((one[1] - two[1]));
        b = ((one[0] * two[1] - one[1] * two[0]));
        begin = (one[1] < two[1] ? one[1] : two[1]) - 1;
        while (++begin <= (one[1] < two[1] ? two[1] : one[1]))
            mlx_pixel_put(env->mlx, env->win, ((begin * (one[0] - two[0]) - b) / a) + env->mv, begin + env->mv, color(z, z_bis));
    }
}

void    draw_line(double *one, double *two, t_env *env, int z, int z_bis)
{
    if (env->rot)
        rotate(one, two, env);
    one[0] = one[0] * env->zoom;
    one[1] = (one[1] - (z * env->depth)) * env->zoom;        
    two[0] = two[0] * env->zoom;
    two[1] = (two[1] - (z_bis * env->depth)) * env->zoom;
    draw(one, two, env, z, z_bis);
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
            one[0] = x;
            one[1] = y;
            two[0] = x + 1;
            two[1] = y;
            if (env->array_pos[y][x + 1])
                draw_line(one, two, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y][x + 1]));
            one[0] = x;
            one[1] = y;
            two[0] = x;
            two[1] = y + 1;
            if (y + 1 < env->len && env->array_pos[y + 1][x])
                draw_line(one, two, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y + 1][x]));
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
