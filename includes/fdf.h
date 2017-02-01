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

# define WIDTH 400
# define LENGTH 400

/*typedef struct		s_pos
{
    int				x;
    int				y;
    int				z;
}               	t_pos;
*/
typedef struct		s_env
{
    void			*mlx;
    void			*win;
    int             len;
    int				x;
    int				y;
}					t_env;

char	***read_file(char ***map, int fd);
void    draw_line(float *one, float *two, t_env *env);
void    draw_map(char ***array_pos, t_env *env);

#endif
