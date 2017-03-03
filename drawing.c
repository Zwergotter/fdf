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

// void    rot_xate(double *one, double *two, t_env *env)
// {
//     one[0] = (one[0] * cos(env->rot * 2 * M_PI / 360)) - (one[1] * sin(env->rot * 2 * M_PI / 360));
//     one[1] = (one[0] * sin(env->rot * 2 * M_PI / 360)) + (one[1] * cos(env->rot * 2 * M_PI / 360));
//     two[0] = (two[0] * cos(env->rot * 2 * M_PI / 360)) - (two[1] * sin(env->rot * 2 * M_PI / 360));
//     two[1] = (two[0] * sin(env->rot * 2 * M_PI / 360)) + (two[1] * cos(env->rot * 2 * M_PI / 360));
// }

void    draw(double *one, double *two, t_env *env, int z, int z_bis)
{
    double begin;
    double a;
    double b;

    if (one[0] == two[0] && one[1] == two[1])
        mlx_pixel_put(env->mlx, env->win, one[0], one[1], color(z, z_bis));
    else if (fabs(one[1] - two[1]) <= fabs(one[0] - two[0]))
    {
        a = ((one[1] - two[1]) / (one[0] - two[0]));
        b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
        begin = (one[0] < two[0] ? one[0] : two[0]) - 1;
        while (++begin <= (one[0] < two[0] ? two[0] : one[0]))
            mlx_pixel_put(env->mlx, env->win, begin, (a * begin + b), color(z, z_bis));
    }
    else
    {
        a = ((one[1] - two[1]));
        b = ((one[0] * two[1] - one[1] * two[0]));
        begin = (one[1] < two[1] ? one[1] : two[1]) - 1;
        while (++begin <= (one[1] < two[1] ? two[1] : one[1]))
            {
                // printf("%f\n", begin);
                mlx_pixel_put(env->mlx, env->win, ((begin * (one[0] - two[0]) - b) / a), begin, color(z, z_bis));
            }
    }
}

void    draw_line(double *one, double *two, t_env *env, int z, int z_bis)
{
    // if (env->rot)
    //     rotate(one, two, env);
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

#include <stdio.h>

void check_before_draw(t_env *env, double *one, double *two)
{
    int x;
    int y;                                        
                  
    y = -1;
    while (env->array_pos[++y])
    {
        one[0] = 0;
        one[1] = y;
        x = -1;
        while (env->array_pos[y + 1] && env->array_pos[y + 1][++x])
        {
            two[0] = one[0] + sin(env->rot_y * 2 * M_PI / 360);
            two[1] = one[1] - cos(env->rot_y * 2 * M_PI / 360);
            if (env->array_pos[y][x + 1])
                draw_line(one, two, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y][x + 1]));
            two[0] = one[0] - sin(env->rot_x * 2 * M_PI / 360);
            two[1] = one[1] + cos(env->rot_x * 2 * M_PI / 360);
            draw_line(one, two, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y + 1][x]));
            one[0] = two[0];
            one[1] = two[1];
        }

    }
}

// void check_before_draw(t_env *env, double *one, double *two)
// {
//     int x;
//     int y;

//     y = -1;
//     while (env->array_pos[++y])
//     {
//         x = -1;
//         while (env->array_pos[y][++x] != '\0')
//         {
//             one[0] = x;
//             one[1] = y;
//             two[0] = x + 1;
//             two[1] = y;
//             if (env->array_pos[y][x + 1])
//                 draw_line(one, two, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y][x + 1]));
//             one[0] = x;
//             one[1] = y;
//             two[0] = x;
//             two[1] = y + 1;
//             if (y + 1 < env->len && env->array_pos[y + 1][x])
//                 draw_line(one, two, env, ft_atoi(env->array_pos[y][x]), ft_atoi(env->array_pos[y + 1][x]));
//         }
//     }
// }

int draw_map(t_env *env)
{
    double one[2];
    double two[2];
    // t_error error;

    // error = MALLOC;
    // if ((!(one = (double*)malloc(sizeof(double) * 2))) || (!(two = (double*)malloc(sizeof(double) * 2))))
        // error_displayed(error);
    one[0] = 0;
    one[1] = 0;
    two[0] = 0;
    two[1] = 0;
    check_before_draw(env, one, two);
    return (1);
}
