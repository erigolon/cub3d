#include "../include/cub3d.h"

void	get_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->wall_2d = mlx_load_png("./textures/wall.png");
	game->textu->floor_2d = mlx_load_png("./textures/floor.png");
	game->textu->my_guy = mlx_load_png("./textures/my_guy.png");

}

void	get_images(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_images));
	game->imag->wall_2d = mlx_texture_to_image(game->mlx, game->textu->wall_2d);
	game->imag->floor_2d = mlx_texture_to_image(game->mlx, game->textu->floor_2d);
	game->imag->my_guy = mlx_texture_to_image(game->mlx, game->textu->my_guy);
	mlx_delete_texture(game->textu->wall_2d);
	mlx_delete_texture(game->textu->floor_2d);
	mlx_delete_texture(game->textu->my_guy);
}

void	draw_guy(t_game *game, t_images *images)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, images->my_guy, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_images *images)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, images->wall_2d, x * 32, y * 32);
			if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, images->floor_2d, x * 32, y * 32);
			x++;
		}
		y++;
	}
	draw_guy(game, images);
}
