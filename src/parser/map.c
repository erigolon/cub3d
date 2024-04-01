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
	char	**new_map;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (game->map_height_dd + 3));
	new_map[0] = ft_calloc(game->map_width_dd + 3, sizeof(char));
	ft_line_x(new_map[0], game->map_width_dd + 2);
	while (game->map[i])
	{
		new_map[i + 1] = ft_calloc(game->map_width_dd + 3, sizeof(char));
		ft_line_x(new_map[i + 1], 1);
		j = 0;
		while (game->map[i][j])
		{
			new_map[i + 1][j + 1] = game->map[i][j];
			j++;
		}
		new_map[i + 1][j + 1] = 'x';
		i++;
	}
	new_map[i + 1] = ft_calloc(game->map_width_dd + 3, sizeof(char));
	ft_line_x(new_map[i + 1], game->map_width_dd + 2);
	new_map[game->map_height_dd + 2] = NULL;
	ft_free(game->map);
	game->map = new_map;
}
