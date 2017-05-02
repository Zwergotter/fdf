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
		return (0xeab0ee);
	if (color1 <= 0 && color2 <= 0)
		return (0xc992fd);
	if (color1 < 10 && color2 < 10)
		return (0xccfabff);
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

int		cold_to_hot(int color1, int color2)
{
	if (color1 < -20 && color2 < -20)
		return (0x062AE0);
	if (color1 <= 0 && color2 <= 0)
		return (0x1A05DB);
	if (color1 < 10 && color2 < 10)
		return (0x5104D7);
	if (color1 < 20 && color2 < 20)
		return (0x8703D3);
	if (color1 < 30 && color2 < 30)
		return (0xBA02CF);
	if (color1 < 50 && color2 < 50)
		return (0xCB02AA);
	if (color1 < 80 && color2 < 80)
		return (0xC70171);
	if (color1 < 150 && color2 < 150)
		return (0xBF0007);
	if (color1 < 190 && color2 < 190)
		return (0xCE031F);
	else
		return (0xCE6103);
}

int		rainbow(int color1, int color2)
{
	if (color1 < -20 && color2 < -20)
		return (0x0655E0);
	if (color1 <= 0 && color2 <= 0)
		return (0x05AFDE);
	if (color1 < 10 && color2 < 10)
		return (0x05DCAF);
	if (color1 < 20 && color2 < 20)
		return (0x04DA55);
	if (color1 < 30 && color2 < 30)
		return (0x0DD804);
	if (color1 < 50 && color2 < 50)
		return (0x65D604);
	if (color1 < 80 && color2 < 80)
		return (0xBBD403);
	if (color1 < 150 && color2 < 150)
		return (0xD19403);
	if (color1 < 190 && color2 < 190)
		return (0xD03C03);
	else
		return (0xCCE021F);
}

int		color(t_env *env, int color1, int color2)
{
	if (env->key == 0 || env->key == 29)
		return (earth(color1, color2));
	if (env->key == 19)
		return (cold_to_hot(color1, color2));
	if (env->key == 20)
		return (rainbow(color1, color2));
	else
		return (technicolor(color1, color2));
}
