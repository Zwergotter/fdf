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

# define FDF_NAME_WIN "fdf"

# define FDF_ZOOM 2
# define FDF_Z_MINI 2
# define FDF_Z_MAX 60

# define FDF_DEPTH 0.05
# define FDF_D_MINI -1
# define FDF_D_MAX 1

# define FDF_ROT 10
# define FDF_R_MINI 0
# define FDF_R_MAX 360

# define FDF_MOVING 50


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
    int             rot_x;
    int             rot_y;
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

int     key_pressed(int keycode, t_env *env);

int     color(int color1, int color2);
void    modify_zoom(t_env *env, int keycode);
void    moving_map(t_env *env, int keycode);
void    changing_depth(t_env *env, int keycode);
void    apply_rot(t_env *env, int keycode);

#endif
