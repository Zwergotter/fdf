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

void	read_file(int fd)
{
    char *line = NULL;
    char **tmp;
    int i;

    while ((i = get_next_line(fd, &line) == 1))
    {
        tmp = ft_strsplit(line, ' ');
        /*
        ** we read a line from input file.
        ** we use strsplit to a have a proper line.
        ** Need to know position of x, of y and then to know what number is in
        ** each part of double array temp.
        ** x = we increase a counter until end of temp. then we reset it.
        ** y  = we increase it a the end of temp read.
        ** z = we can know it with atoi (or get_nbr?)
        */
    }
}
