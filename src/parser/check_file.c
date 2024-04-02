#include "../../include/cub3d.h"

void	ft_get_map(t_game *game, int tam_map, int start_map)
{
	int	i;
	int	j;

	j = 0;
	i = start_map;
	game->map = (char **)malloc(sizeof(char *) * (tam_map + 1));
	if (!game->map)
		return ;
	while (tam_map != 0)
	{
		game->map[j] = ft_strdup(game->data[i]);
		j++;
		i++;
		tam_map--;
	}
	game->map[j] = NULL;
	return ;
}

void	ft_map_rectangle(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->new_map = (char **)malloc(sizeof(char *) * (game->map_height_dd + 3));
	game->new_map[0] = ft_calloc(game->map_width_dd + 3, sizeof(char));
	ft_line_x(game->new_map[0], game->map_width_dd + 2);
	while (game->map[i])
	{
		game->new_map[i + 1] = ft_calloc(game->map_width_dd + 3, sizeof(char));
		ft_line_x(game->new_map[i + 1], 1);
		j = 0;
		while (game->map[i][j])
		{
			game->new_map[i + 1][j + 1] = game->map[i][j];
			j++;
		}
		game->new_map[i + 1][j + 1] = 'x';
		i++;
	}
	game->new_map[i + 1] = ft_calloc(game->map_width_dd + 3, sizeof(char));
	ft_line_x(game->new_map[i + 1], game->map_width_dd + 2);
	game->new_map[game->map_height_dd + 2] = NULL;
}

void	ft_replace_sp_tab(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->new_map[i])
	{
		j = 0;
		while (game->new_map[i][j])
		{
			if (game->new_map[i][j] == ' ')
				game->new_map[i][j] = 'x';
			if (game->new_map[i][j] == '\t')
				game->new_map[i][j] = 'x';
			j++;
		}
		i++;
	}
}
