#include "../../include/cub3d.h"

void	ft_init_values(t_game *game)
{
	game->mlx = NULL;
	game->map = NULL;
	game->new_map = NULL;
	game->data = NULL;
	game->file_data = NULL;
	game->map_width_dd = 0;
	game->map_height_dd = 0;
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->c_path = NULL;
	game->f_path = NULL;
	game->color_ceiling = 0;
	game->color_floor = 0;
	game->height_data = 0;
}

/*
funcion que verifica si se han extraido todos los datos
*/
int	ft_all_info_extracted(t_game *game)
{
	if (game->no_path && game->so_path && game->we_path
		&& game->ea_path && game->c_path && game->f_path)
		return (1);
	return (0);
}

/*
Esta funcion va filtrando los datos del 
archivo para extraer los valores
*/
int	ft_get_file_data(char **data, t_game *game)
{
	int		i;

	i = 0;
	while (data[i])
	{
		if (ft_strncmp(data[i], "NO ./", 5) == 0
			|| ft_strncmp(data[i], "SO ./", 5) == 0
			|| ft_strncmp(data[i], "WE ./", 5) == 0
			|| ft_strncmp(data[i], "EA ./", 5) == 0
			|| ft_strncmp(data[i], "F ", 2) == 0
			|| ft_strncmp(data[i], "C ", 2) == 0)
			ft_path_texture(data[i], game);
		i++;
		if (ft_all_info_extracted(game))
			return (i);
	}
	return (0);
}

/*
con esta funcion extraigo todas las texturas 
y valores relacionados con el mapa
*/
void	ft_path_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ./", 5) == 0)
		game->no_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ./", 5) == 0)
		game->so_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ./", 5) == 0)
		game->we_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ./", 5) == 0)
		game->ea_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->c_path = ft_strdup(line + 2);
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->f_path = ft_strdup(line + 2);
}

int	ft_check_texture(t_game *game)
{
	if (!game->no_path || !game->so_path || !game->we_path
		|| !game->ea_path || !game->c_path || !game->f_path)
		return (1);
	return (0);
}
