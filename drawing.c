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

void    draw_line(int *first, int *second, t_env *env)
{
    int start;
    double a;
    double b;

    if (first[0] == second[0] && first[1] == second[1])
        mlx_pixel_put(env->mlx, env->win, first[0], first[1], 00255100000);
    else if (abs(first[1] - second[1]) <= abs(first[0] - second[0]))
    {
        a = ((first[1] - second[1]) / (first[0] - second[0]));
        b = ((first[0] * second[1] - first[1] * second[0]) / (first[0] - second[0]));
        start = (first[0] < second[0] ? first[0] : second[0]) - 1;
        while (++start <= (first[0] < second[0] ? second[0] : first[0]))
            mlx_pixel_put(env->mlx, env->win, start, (a * start + b), 00255100000);
    }
    else
    {
        a = ((first[1] - second[1]));
        b = ((first[0] * second[1] - first[1] * second[0]));
        start = (first[1] < second[1] ? first[1] : second[1]) - 1;
        while (++start <= (first[1] < second[1] ? second[1] : first[1]))
            mlx_pixel_put(env->mlx, env->win, (start * (first[0] - second[0]) - b) / a, start, 00255100000);
    }
}
