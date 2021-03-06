/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:27:21 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 17:20:25 by edeveze          ###   ########.fr       */
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

# define FDF_ZOOM 0.5
# define FDF_Z_MINI 1
# define FDF_Z_MAX 30

# define FDF_DEPTH 0.01
# define FDF_D_MINI -0.5
# define FDF_D_MAX 0.5

# define FDF_ROT 10
# define FDF_R_MINI 0
# define FDF_R_MAX 360

# define FDF_MOVING	50

typedef	struct		s_coord
{
	double			one[2];
	double			two[2];
	int				x;
	int				y;
	int				z[2];
}					t_coord;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*p_img;
	int				bpp;
	int				s_line;
	int				ed;
	char			***array_pos;
	int				len;
	int				win_x;
	int				win_y;
	double			zoom;
	double			depth;
	int				mv_x;
	int				mv_y;
	int				rot_x;
	int				rot_y;
	int				key;
	double			coord_x;
	double			coord_y;
}					t_env;

typedef	enum		e_error
{
	ARGUMENT, MALLOC, OPEN, USAGE
}					t_error;

void				init_everything(t_env *env, char *map);
char				***read_file(char ***map, int fd);
void				depth(t_env *env);

int					draw_map(t_env *env);
void				check_before_draw(t_env *env, t_coord *coord);

void				printcontrol(t_env *env);

void				error_displayed(t_error error);

int					key_pressed(int keycode, t_env *env);

int					color(t_env *env, int color1, int color2);
void				modify_zoom(t_env *env, int keycode);
void				moving_map(t_env *env, int keycode);
void				changing_depth(t_env *env, int keycode);
void				apply_rot(t_env *env, int keycode);

#endif
