/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:27:21 by edeveze           #+#    #+#             */
/*   Updated: 2017/02/16 18:52:51 by cosi             ###   ########.fr       */
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

typedef struct		s_env
{
    void			*mlx;
    void			*win;
    int             len;
    int				win_x;
    int				win_y;
    int             zoom;
    int             move;
    int             rotation;
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
void    apply_rotation(t_env *env);
int     key_pressed(int keycode, t_env *env);

#endif
