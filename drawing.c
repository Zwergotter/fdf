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

void    draw_line(int *one, int *two, t_env *env)
{
    int start;
    double a;
    double b;

    if (one[0] == two[0] && one[1] == two[1])
        mlx_pixel_put(env->mlx, env->win, one[0], one[1], 00255100000);
    else if (abs(one[1] - two[1]) <= abs(one[0] - two[0]))
    {
        a = ((one[1] - two[1]) / (one[0] - two[0]));
        b = ((one[0] * two[1] - one[1] * two[0]) / (one[0] - two[0]));
        start = (one[0] < two[0] ? one[0] : two[0]) - 1;
        while (++start <= (one[0] < two[0] ? two[0] : one[0]))
            mlx_pixel_put(env->mlx, env->win, start, (a * start + b), 00255100000);
    }
    else
    {
        a = ((one[1] - two[1]));
        b = ((one[0] * two[1] - one[1] * two[0]));
        start = (one[1] < two[1] ? one[1] : two[1]) - 1;
        while (++start <= (one[1] < two[1] ? two[1] : one[1]))
            mlx_pixel_put(env->mlx, env->win, (start * (one[0] - two[0]) - b) / a, start, 00255100000);
    }
}

void draw_map(char ***array_pos, t_env *env)
{
    int *one = NULL;
    int *two = NULL;
    int x;
    int y;
    
    if ((!(one = (int*)malloc(sizeof(int) * 2))) || (!(two = (int*)malloc(sizeof(int) * 2))))
        exit (-1);
    y = -1;
    while (array_pos[++y])
    {
        x = -1;
        while (array_pos[y][++x])
        {
           
            printf("x, y values %d, %d \n", x, y);
            printf("z value is %d \n", ft_atoi(array_pos[y][x]));
            one[0] = x;
            one[1] = y - ft_atoi(array_pos[y][x]);
            printf("one values %d, %d \n", one[0], one[1]);
            if (array_pos[y][x + 1] != '\0')
            {
                printf("\x1b[31mif1 exists\n\x1b[0m");
                two[0] = x + 1;
                two[1] = y - ft_atoi(array_pos[y][x + 1]);
                printf("\x1b[31mtwo values next x: %d; %d; %d \n\x1b[0m", two[0], two[1], ft_atoi(array_pos[y][x + 1]));
                draw_line(one, two, env);
            }
            if (y + 1 < env->len)
            {
                printf("\x1b[32mif2 exists\n\x1b[0m");
                two[0] = x;
                two[1] = y + 1 - ft_atoi(array_pos[y + 1][x]);
                printf("\x1b[32mtwo values next y: %d; %d; %d \n\x1b[0m", two[0], two[1], ft_atoi(array_pos[y + 1][x]));
                draw_line(one, two, env);
            }
        }
    }
}
