#include "fdf.h"


void	apply_rotation(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 125) /////////////////////////////////////////////////keycode for up and 8
		{
			if (env->rotation == 360)
				env->rotation = 0;
			env->rotation += 5;
		}
	if (keycode == 126) /////////////////////////////////////////////////keycode for down and 2
		{
			if (env->rotation == 0)
				env->rotation = 360;
			env->rotation -= 5;
		}
	draw_map(env);
}
