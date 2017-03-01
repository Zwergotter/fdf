/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:27:21 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/24 14:22:48 by edeveze          ###   ########.fr       */
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
** Libraries for perror and strerror.
*/

# include <stdio.h>
# include <string.h>

# include <math.h>
# include "mlx.h"
# include "libft.h"

# define NAME_WIN "fdf"

# define ZOOM 3
# define Z_MINI 3
# define Z_MAX 60

# define DEPTH 0.05
# define D_MINI -1
# define D_MAX 1

# define ROT 10
# define R_MINI 0
# define R_MAX 360

# define MOVING 10


typedef struct		s_env
{
    void			*mlx;
    void			*win;
    int             len;
    int             max_x;
    int             min_y;
    int             max_y;
    int				win_x;
    int				win_y;
    int             zoom;
    int             mv_x;
    int             mv_y;
    int             rot;
    double          depth;
    char            ***array_pos;
}					t_env;

typedef enum e_error
{
    ARGUMENT, MALLOC, OPEN, USAGE
}            t_error;

void    init_everything(t_env *env, char *map);
char	***read_file(char ***map, int fd);
int     draw_map(t_env *env);
void    error_displayed(t_error error);
void    apply_rot(t_env *env, int keycode);
int     key_pressed(int keycode, t_env *env);
int     color(int color1, int color2);

#endif
