#include "../include/cub3d.h"

double	find_player_pos_x(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (check_guy(game->map[y][x]))
				return ((x * 32) + (32 / 2));
			x++;
		}
		y++;
	}
}

double	find_player_pos_x(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (check_guy(game->map[y][x]))
				return ((y * 32) + (32 / 2));
			x++;
		}
		y++;
	}
}

void	init_player_struct(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->pos_x = find_player_pos_x(game);
	game->player->pos_y = find_player_pos_y(game);
}
