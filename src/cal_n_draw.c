#include "../include/cub3d.h"

static void	draw_sky_floor(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y <= W_HEIGHT / 2)
	{
		mlx_put_pixel(game->image, x, y, game->color_ceiling);
		y++;
	}
	while (y < W_HEIGHT)
	{
		mlx_put_pixel(game->image, x, y, game->color_floor);
		y++;
	}
}

void	calculate_n_draw(t_game *game)
{
	int		x;
	double	single_ray;

	x = 0;
	game->raycast->angle = game->player->angle - (game->pov / 2);
	single_ray = (game->pov / W_WIDTH);
	while (x < W_WIDTH)
	{
		draw_sky_floor(game, x);
		x++;
	}
}
