#include "fdf.h"

void	rotation(t_env *env)
{
	draw_map(env);
}

void	apply_rotation(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	rotation(env);
}
