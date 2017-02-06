/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 00:07:52 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/29 00:08:06 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void    draw_line(float *one, float *two, t_env *env)
{
    int start;
    double a;
    double b;

    if (one[0] == two[0] && one[1] == two[1])
        mlx_pixel_put(env->mlx, env->win, one[0], one[1], 00255555000);
    else if (fabsf(one[1] - two[1]) <= fabsf(one[0] - two[0]))
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

void draw_map(char ***array_pos, t_env *env)
{
    float *one = NULL;
    float *two = NULL;
    int x;
    int y;
    
    if ((!(one = (float*)malloc(sizeof(float) * 2))) || (!(two = (float*)malloc(sizeof(float) * 2))))
        exit (-1);
    y = -1;
    while (array_pos[++y])
    {
        x = -1;
        while (array_pos[y][++x])
        {
            if (!array_pos[y][x])
                break ;
            one[0] = x * env->zoom;
            one[1] = (y - (ft_atoi(array_pos[y][x]) * env->depth)) * env->zoom;
            if (array_pos[y][x + 1] != '\0')
            {
                two[0] = (x + 1) * env->zoom;
                two[1] = (y - ft_atoi(array_pos[y][x + 1]) * env->depth) * env->zoom;
                draw_line(one, two, env);
            }
            if (y + 1 < env->len)
            {
                two[0] = x * env->zoom;
                two[1] = (y + 1 - ft_atoi(array_pos[y + 1][x]) * env->depth) * env->zoom;
                draw_line(one, two, env);
            }
        }
    }
}
