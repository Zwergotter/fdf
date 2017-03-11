/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:05:25 by edeveze           #+#    #+#             */
/*   Updated: 2017/03/10 17:54:44 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		earth(int color1, int color2)
{
	if (color1 < -20 && color2 < -20)
		return (0x0069FF);
	if (color1 <= 0 && color2 <= 0)
		return (0x0099FF);
	if (color1 < 10 && color2 < 10)
		return (0x006600);
	if (color1 < 20 && color2 < 20)
		return (0x306600);
	if (color1 < 30 && color2 < 30)
		return (0x506600);
	if (color1 < 50 && color2 < 50)
		return (0x887E00);
	if (color1 < 80 && color2 < 80)
		return (0x986E40);
	if (color1 < 150 && color2 < 150)
		return (0x704630);
	if (color1 < 190 && color2 < 190)
		return (0x503630);
	else
		return (0xFFFFFF);
}

int		technicolor(int color1, int color2)
{
	if (color1 < -20 && color2 < -20)
		return (0xECB7EE);
	if (color1 <= 0 && color2 <= 0)
		return (0xd1b7ee);
	if (color1 < 10 && color2 < 10)
		return (0xc9aeff);
	if (color1 < 20 && color2 < 20)
		return (0x7466ff);
	if (color1 < 30 && color2 < 30)
		return (0x6762a3);
	if (color1 < 50 && color2 < 50)
		return (0x051575);
	if (color1 < 80 && color2 < 80)
		return (0x2b90f5);
	if (color1 < 150 && color2 < 150)
		return (0xc6e2ff);
	if (color1 < 190 && color2 < 190)
		return (0xb7eeec);
	else
		return (0xFFFFFF);
}

int		color(t_env *env, int color1, int color2)
{
	if (env->key == 0 || env->key == 29)
		return (earth(color1, color2));
	else
		return (technicolor(color1, color2));
}
