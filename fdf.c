/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:29:35 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/25 19:26:39 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     map_length(int fd)
{
    char buf[1];
    int i;

    i = 0;
    while (read(fd, buf, 1))
    {
        if (buf[0] == '\n')
            i++;
    }
    if (buf[0] != '\n')
        i++;
    return (i);
}

/*void init_everything(t_env *env, char *map, )*/

void init_env(t_env *env, char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	env->win_x = 1200;
	env->win_y = 800;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, "fdf");
	env->len = map_length(fd);
	env->zoom = 5;
	env->depth = 0.1;
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;

		fd = open(file, O_RDONLY);
		array_pos = read_file(array_pos, fd);
		close(fd);
}

int	key_pressed(int keycode)
{
	if (keycode == 53)
		exit (0);
	printf("Code of key pressed is %d\n", keycode);
	return (1);
}

int	main(int ac, char **av)
{
	t_env *env;
	/*t_max *coord;*/
	char ***array_pos;

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			return (-1);
		init_env(env, av[1]);
		if (!(array_pos = (char***)malloc(sizeof(char) * env->len + 1))/* || !(coord = (t_max*)malloc(sizeof(t_max)))*/)
			return (-1);
		array_pos[env->len] = NULL;
		init_array(array_pos, av[1]);
		/*max_coord(array_pos, coord); one segfault here*/
		printf("no segfault2\n");
		/*printf("higher x, y min_heigth and max_heigth are %d, %d, %d, %d\n", coord->max_x, coord->max_y, coord->min_heigth, coord->max_heigth);
		*/draw_map(array_pos, env);
		printf("no segfault3\n"); /*encore*/
		mlx_key_hook(env->win, key_pressed, env);
		mlx_loop(env->mlx); /*segfault around here and previous line mayb as well. if segfault 4 printed, so loop stopped but the map was printed. segfault also sometimes during loop so nothing displayed. WHY*/
		/*Right now, does know how to do with with map which has different sides size and also with no heigth*/
		printf("no segfault4\n");
	}
	return (0);
}
