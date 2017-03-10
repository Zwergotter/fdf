/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:36:57 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/10 18:03:22 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_displayed(t_error error)
{
	if (error == ARGUMENT)
		ft_putstr_fd("File doesn't exist or is not valid\n", 2);
	if (error == MALLOC)
		ft_putstr_fd("Memory allocation failed\n", 2);
	if (error == OPEN)
		ft_putstr_fd("Opening file failed\n", 2);
	if (error == USAGE)
		ft_putstr_fd("Usage: fdf fdf_file\n", 2);
	exit(0);
}
