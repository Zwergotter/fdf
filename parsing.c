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

char    ***read_file(char ***map, int fd, int array_size)
{
    char *line = NULL;
    int i;
    
    i = 0;
    map[array_size] = NULL;
    while (get_next_line(fd, &line) == 1)
    {
        map[i++] = ft_strsplit(line, ' ');
        free(line);
        line = NULL;
    }
    return (map);
}