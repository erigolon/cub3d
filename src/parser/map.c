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
	new_map[game->map_height_dd + 2]
		= ft_calloc(game->map_width_dd + 3, sizeof(char));
	ft_line_x(new_map[0], game->map_width_dd + 2);
	ft_line_x(new_map[game->map_height_dd + 2], game->map_width_dd + 2);
/*
	ahora relleno las filas intermedias con la la primera y ultima columna 
	con x y entre medio con los valores de la matriz original
*/
	while (i < game->map_height_dd)
	{
		new_map[i + 1] = ft_calloc(game->map_width_dd + 3, sizeof(char));
		ft_line_x(new_map[i + 1], 1);
		j = 0;
		while (j < game->map_width_dd)
		{
			new_map[i + 1][j + 1] = game->map[i][j];
			j++;
		}
		ft_line_x(&new_map[i + 1][game->map_width_dd + 1], 1);
		i++;
	}
	ft_free(game->map);
	game->map = new_map;
}
	/*new_map[game->map_height_dd + 2]
		= ft_calloc(game->map_width_dd + 3, sizeof(char));*/

// void	ft_replace_str(char **new_map, char a, char b)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (new_map[0][j])
// 	{
// 		j = 0;
// 		while (new_map[i][j])
// 		{
// 			if (new_map[i][j] == a)
// 				new_map[i][j] = b;
// 			j++;
// 		}
// 		i++;
// 	}
// }

