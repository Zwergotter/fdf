/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:08:40 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/09 13:03:54 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     check_parsing(char **map)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (!(map[y][x] > 47 && map[y][x] < 58) && !(map[y][x] == '-'))
                return (0);
            x++;
        }
        y++;
    }
    return (1);
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
    while ((get_next_line(fd, &line)) > 0)
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
    if ((get_next_line(fd, &line)) < 0 || !(check_parsing(*map)))
        return (NULL);
    return (map);
}
