#include "../include/cub3d.h"

void	rotate(t_game *game, int dir)
{
	(void)dir;
	(void)game;
}

void	move(t_game *game, int dir)
{
	(void)dir;
	(void)game;
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(game, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, 2);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(game, 3);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, 4);
	calculate_n_draw(game);
}
