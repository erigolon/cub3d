#include "../include/cub3d.h"

static void	init_player_struct(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->pos_x = -1;
	game->player->pos_y = -1;
}

static void	init_texture_struct(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->no_textu = mlx_load_png(game->no_path);
	game->textu->so_textu = mlx_load_png(game->so_path);
	game->textu->we_textu = mlx_load_png(game->we_path);
	game->textu->ea_textu = mlx_load_png(game->ea_path);
}

void	init_mlx_struct(t_game *game)
{
	init_player_struct(game);
	init_texture_struct(game);
	game->window_width = W_WIDTH;
	game->window_height = W_HEIGHT;
}
