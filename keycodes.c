 #include "fdf.h"

void modify_zoom(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 24)
		env->zoom += 5;
	else
		env->zoom -=5;
	draw_map(env);
}

void moving_map(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 123)
		env->move -= 5;
	else
		env->move += 5;
	draw_map(env);
}

int	key_pressed(int keycode, t_env *env)
{
	if (keycode == 125 || keycode == 126)
		apply_rotation(env, keycode);
	if ((keycode == 24 && env->zoom < ZOOM_MAX) || (keycode == 27 && env->zoom > ZOOM_MINI))
		modify_zoom(env, keycode);
	if (keycode == 123 || keycode == 124)
		moving_map(env, keycode);
	if (keycode == 53)
		exit (0);
	printf("Code of key pressed is %d\n", keycode);
	return (1);
}