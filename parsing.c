/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:08:40 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/26 14:13:40 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void max_coord(char ***map, t_max *coord)
{
    int y;
    int x;

    y = 0;
    coord->max_heigth = 0;
    coord->min_heigth = 0;
    while (map[y])
    {
        x = 0;
        while(map[x])
        {
            if (ft_atoi(map[y][x]) > coord->max_heigth)
                coord->max_heigth = ft_atoi(map[y][x]);
            if (ft_atoi(map[y][x]) < coord->min_heigth)
                coord->min_heigth = ft_atoi(map[y][x]);
            x++;
        }
        y++;
    }
    coord->max_x = x - 1;
    coord->max_y = y - 1;
}

char    ***read_file(char ***map, int fd)
{
    char *line = NULL;
    char **temp = NULL;
    int i;
    int actual_len;
    int split_len;
    
    i = -1;
    actual_len = 0;
    while ((get_next_line(fd, &line)) == 1)
    {
        split_len = 0;
        temp = ft_strsplit(line, ' ');
        while (temp[split_len])
            split_len++;
        if ((actual_len && split_len != actual_len) || split_len == 0)
            return (NULL);
        actual_len = split_len;
        map[++i] = temp;
        free(line);
    }
    if ((get_next_line(fd, &line) < 0))
        return (NULL);
    free(line);
    return (map);
}