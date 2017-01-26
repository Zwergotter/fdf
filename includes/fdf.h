/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:27:21 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/25 19:08:19 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Libraries for open, read, write and close.
*/

# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** Library for malloc, free and exit.
*/

# include <stdlib.h>

/*
** Libraries for perror adnd strerror.
*/

# include <stdio.h>
# include <string.h>

# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_node
{
    int x;
    int y;
    int z;
}				t_node;

void	read_file(int fd);

#endif
