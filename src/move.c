#include "../include/cub3d.h"

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->imag->my_guy->instances->y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->imag->my_guy->instances->y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->imag->my_guy->instances->x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->imag->my_guy->instances->x += 5;
}
