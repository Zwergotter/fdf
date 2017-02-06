/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:27:21 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/26 17:58:00 by edeveze          ###   ########.fr       */
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

typedef struct		s_env
{
    void			*mlx;
    void			*win;
    int             len;
    int				win_x;
    int				win_y;
    int             zoom;
    float           depth;
}					t_env;

/*typedef struct      s_max
{
    int             max_heigth;
    int             min_heigth;
    int             max_x;
    int             max_y;
}                   t_max;*/

char	***read_file(char ***map, int fd);
void    draw_line(float *one, float *two, t_env *env);
void    draw_map(char ***array_pos, t_env *env);
/*void    max_coord(char ***map, t_max *coord);*/

#endif
