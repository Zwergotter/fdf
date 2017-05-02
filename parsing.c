/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:08:40 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/17 17:16:36 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Checks that all parsed values are numbers.
*/

int		check_parsing(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] > 47 && map[y][x] < 58) && !(map[y][x] == '-'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
** Functions to define a better depth.
*/

void	depth(t_env *env)
{
	int		max_z;
	int		x;
	int		y;
	double	depth;

	max_z = 0;
	y = -1;
	while (env->array_pos[++y])
	{
		x = -1;
		while (env->array_pos[y][++x])
		{
			if (ft_atoi(env->array_pos[y][x]) > max_z)
				max_z = ft_atoi(env->array_pos[y][x]);
			if (-ft_atoi(env->array_pos[y][x]) > max_z)
				max_z = -ft_atoi(env->array_pos[y][x]);
		}
	}
	depth = max_z;
	while (depth >= FDF_D_MAX)
		depth = depth / 10;
	env->depth = depth;
}

/*
** Reads file ine by line and puts each of them in ***map.
** If get_next_line or check_parsing returns an error, fucntion
** returns NULL. Else it returns the map.
*/

char	***read_file(char ***map, int fd)
{
	char	*line;
	char	**temp;
	int		i;
	int		split_len;

	i = -1;
	while ((get_next_line(fd, &line)) > 0)
	{
		split_len = 0;
		temp = ft_strsplit(line, ' ');
		while (temp[split_len])
			split_len++;
		if (split_len == 0)
			return (NULL);
		map[++i] = temp;
		free(line);
	}
	if ((get_next_line(fd, &line)) < 0 || !(check_parsing(*map)))
		return (NULL);
	return (map);
}
