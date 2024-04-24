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
	game->check_no = 0;
	game->check_so = 0;
	game->check_we = 0;
	game->check_ea = 0;
	game->check_c = 0;
	game->check_f = 0;
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

int	ft_check_texture(t_game *game)
{
	if (!game->no_path || !game->so_path || !game->we_path
		|| !game->ea_path || !game->c_path || !game->f_path)
		return (1);
	return (0);
}

void	ft_extrexct_path(char **cpy_data, t_game *game)
{
	int	i;

	i = 0;
	while (cpy_data)
	{
		if (cpy_data[i] && ft_strncmp(cpy_data[i], "NO ", 3) == 0)
			ft_check_no(cpy_data[i], game);
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "SO ", 3) == 0)
			ft_check_so(cpy_data[i], game);
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "WE ", 3) == 0)
			ft_check_we(cpy_data[i], game);
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "EA ", 3) == 0)
			ft_check_ea(cpy_data[i], game);
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "C ", 2) == 0)
			ft_check_c(cpy_data[i], game);
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "F ", 2) == 0)
			ft_check_f(cpy_data[i], game);
		i++;
		if (ft_check_all_path(game) == 1 && ft_no_found_path(cpy_data[i]) == 1)
			return (ft_perror("Error in data path"));
	}

}

int	ft_check_all_path(t_game *game)
{
	if (game->check_no && game->check_so && game->check_we
		&& game->check_ea && game->check_c && game->check_f)
		return (1);
	return (0);
}

int	ft_no_found_path(char *data)
{
	if (data && ft_strncmp(data, "NO ", 3) != 0
		&& ft_strncmp(data, "SO ", 3) != 0
		&& ft_strncmp(data, "WE ", 3) != 0
		&& ft_strncmp(data, "EA ", 3) != 0
		&& ft_strncmp(data, "C ", 2) != 0
		&& ft_strncmp(data, "F ", 2) != 0)
		return (1);
	return (0);
}
/*
Esta funcion va filtrando los datos del 
archivo para extraer los valores
*/

/*La pregunta es que pasa si lo hago al reves,
si recorro sacando los datos hasta encontrar */
/*
int	ft_get_file_data(char **data, t_game *game)
{
	int	i;
	int	data_compleate;

	i = 0;
	data_compleate = 0;
	while (data[i])
	{
		if (ft_check_no(data[i], game)
			|| ft_check_so(data[i], game)
			|| ft_check_ea(data[i], game)
			|| ft_check_we(data[i], game)
			|| ft_check_c(data[i], game)
			|| ft_check_f(data[i], game))
			return (ft_perror("Error data map"));
		if (ft_all_info_extracted(game))
			data_compleate = 1;
		i++;
		if (ft_check_line(data[i]) && data_compleate == 0)
		{
			printf("\ndata %s\n", game->f_path);
			printf("\ndata %s\n", game->no_path);
			printf("\ndata %s\n", game->so_path);
			printf("\ndata %s\n", game->we_path);
			printf("\ndata %s\n", game->ea_path);
			printf("\ndata %s\n", game->c_path);
			return (ft_perror("Error with data map"));
		}
	}
	return (0);
}

con esta funcion extraigo todas las texturas 
y valores relacionados con el mapa
*/
/*
void	ft_path_texture(char *line, t_game *game)
{
	printf("\nline %s\n", line);
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
*/
