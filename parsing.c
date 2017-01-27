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

t_pos   **setting_pos(t_pos **array_pos, char ***array)
{   
    int x;
    int y;

    x = 0;
    y = 0;
    while(array[y])
    {
        x = 0;
        while(array[y][x])
        {
            (*array_pos)->x = x;
            (*array_pos)->y = y;
            (*array_pos)->z = ft_atoi(array[x][y]);
            x++;
            array_pos++;
        }
        y++;
    }
    return (array_pos);
}

t_pos    **read_file(int fd)
{
    char *line = NULL;
    char ***tmp;
    int y;
    t_pos  **array_pos;
    
    y = 0;
    if (!(tmp = (char***)malloc(sizeof(char))))
        return (NULL);
    while (get_next_line(fd, &line) == 1)
    {
        tmp[y++] = ft_strsplit(line, ' ');
        free(line);
        line = NULL;
    }
    if (!(array_pos = (t_pos**)malloc(sizeof(t_pos) * y )))
        return (NULL);
    array_pos = setting_pos(array_pos, tmp);
    free(tmp);
    return (array_pos);
}
