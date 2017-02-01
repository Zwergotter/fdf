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

void init_env(t_env *env, char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	env->x = 50;
	env->y = 50;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, LENGTH, "fdf");
	env->len = map_length(fd);
	close(fd);
}

void init_array(char ***array_pos, char *file)
{
		int		fd;

		fd = open(file, O_RDONLY);
		array_pos = read_file(array_pos, fd);
		close(fd);
}

void	print_map(char ***array_pos) ////////////////////////////////////////////////////////////////// TO DELETE
{
	int i;
	int j;

	i = -1;
	printf("\x1b[35mPrinting parsing\n\x1b[0m");
	while (array_pos[++i])
	{
		j = -1;
		while(array_pos[i][++j])
		{
			printf("\x1b[35m%s \x1b[0m", array_pos[i][j]);
		}
		printf("\n");
	}
	printf("\x1b[35mParsing done\n\x1b[0m");
}

int	main(int ac, char **av)
{
	t_env *env;
	char ***array_pos;
	/*int first[2] = {213, 160};
 	int second[2] = {10, 300};*/

	if (ac == 2)
	{
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			return (-1);
		init_env(env, av[1]);
		if (!(array_pos = (char***)malloc(sizeof(char) * env->len + 1)))
			return (-1);
		array_pos[env->len] = NULL;
		init_array(array_pos, av[1]);
		print_map(array_pos);
		printf("length map is %d\n", env->len);
		/*draw_line(first, second, env);
		*/draw_map(array_pos, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
