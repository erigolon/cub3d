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
	game->i_textu.no_path = NULL;
	game->i_textu.so_path = NULL;
	game->i_textu.we_path = NULL;
	game->i_textu.ea_path = NULL;
	game->i_textu.c_path = NULL;
	game->i_textu.f_path = NULL;
	game->height_data = 0;
	game->i_textu.check_no = 0;
	game->i_textu.check_so = 0;
	game->i_textu.check_we = 0;
	game->i_textu.check_ea = 0;
	game->i_textu.check_c = 0;
	game->i_textu.check_f = 0;
}

/*
funcion que verifica si se han extraido todos los datos
*/
int	ft_all_info_extracted(t_game *game)
{
	if (game->i_textu.no_path && game->i_textu.so_path && game->i_textu.we_path
		&& game->i_textu.ea_path && game->i_textu.c_path && game->i_textu.f_path)
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
	int	data_compleate;

	data_compleate = 0;
	while (data[i])
	{
		if (ft_check_no(data[i], game)
			|| ft_strncmp(data[i], "SO ./", 5) == 0
			|| ft_strncmp(data[i], "WE ./", 5) == 0
			|| ft_strncmp(data[i], "EA ./", 5) == 0
			|| ft_strncmp(data[i], "F ", 2) == 0
			|| ft_strncmp(data[i], "C ", 2) == 0)
			ft_path_texture(data[i], game);
		if (ft_all_info_extracted(game))
			data_compleate = 1;
		i++;
		if (data[i] && data_compleate == 0 && (ft_strncmp(data[i], "1", 1) == 0 || ft_strncmp(data[i], "0", 1) == 0))
			ft_error("Error in map");
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
		game->i_textu.no_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ./", 5) == 0)
		game->i_textu.so_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ./", 5) == 0)
		game->i_textu.we_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ./", 5) == 0)
		game->i_textu.ea_path = ft_strdup(line + 3);
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->i_textu.c_path = ft_strdup(line + 2);
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->i_textu.f_path = ft_strdup(line + 2);
}

int	ft_check_texture(t_game *game)
{
	if (!game->i_textu.no_path || !game->i_textu.so_path || !game->i_textu.we_path
		|| !game->i_textu.ea_path || !game->i_textu.c_path || !game->i_textu.f_path)
		return (1);
	return (0);
}

