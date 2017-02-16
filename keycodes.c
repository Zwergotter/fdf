 #include "fdf.h"

int	key_pressed(int keycode, t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 91 || keycode == 126) /////////////////////////////////////////////////keycode for up and 8
		{
			if (env->rotation == 360)
				env->rotation = 0;
			env->rotation += 5;
			apply_rotation(env);
		}
	if (keycode == 84 || keycode == 125) /////////////////////////////////////////////////keycode for down and 2
		{
			if (env->rotation == 0)
				env->rotation = 360;
			env->rotation -= 5;
			apply_rotation(env);
		}
	if (keycode == 53)
		exit (0);
	printf("Code of key pressed is %d\n", keycode);
	return (1);
}