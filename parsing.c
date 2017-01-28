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

char    ***read_file(char ***map, int fd)
{
    char *line = NULL;
    char **temp = NULL;
    int i;
    int actual_len;
    int split_len;
    
    i = 0;
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
        map[i++] = temp;
        free(line);
    }
    return (map);
}