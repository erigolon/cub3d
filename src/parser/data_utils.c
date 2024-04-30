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
	game->start_map = 0;
	game->color_ceiling = 0;
	game->color_floor = 0;
	game->height_data = 0;
}

/*
funcion que verifica si se han extraido todos los datos
*/

int	ft_check_all_extracted(t_game *game)
{
	if (game->no_path && game->so_path && game->we_path
		&& game->ea_path && game->c_path && game->f_path)
		return (0);
	return (1);
}

int	ft_check_texture(t_game *game)
{
	if (!game->no_path || !game->so_path || !game->we_path
		|| !game->ea_path || !game->c_path || !game->f_path)
		return (1);
	return (0);
}

void	ft_extract_path(char **cpy_data, t_game *game)
{
	int	i;
	int	all_path;

	all_path = 6;
	i = 0;
	while (cpy_data[i] || all_path != 0)
	{
		if (cpy_data[i] && ft_line_empty_2(cpy_data[i]) && game->no_path == NULL)
		{
			if (game->no_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data North");
			all_path--;
		}
		else if (cpy_data[i] && ft_line_empty_2(cpy_data[i]) && game->so_path == NULL)
		{
			if (game->so_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error data south");
			all_path--;
		}
		else if (cpy_data[i] && ft_line_empty_2(cpy_data[i]) && game->we_path == NULL)
		{
			if (game->we_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error data West");
			all_path--;
		}
		else if (cpy_data[i] && ft_line_empty_2(cpy_data[i]) && game->ea_path == NULL)
		{
			if (game->ea_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error data East");
			all_path--;
		}
		else if (cpy_data[i] && ft_line_empty_2(cpy_data[i]) && game->c_path == NULL)
		{
			if (game->c_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error data Ceilling");
			all_path--;
		}
		else if (cpy_data[i] && ft_line_empty_2(cpy_data[i]) && game->f_path == NULL)
		{
			if (game->f_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data floor");
			all_path--;
		}
		if (all_path != 0 && !ft_line_empty_2(cpy_data[i]))
			ft_perror("Error no have all path");
		else
			i++;
	}

}

/*
Esta funcion va filtrando los datos del 
archivo para extraer los valores
*/

/*La pregunta es que pasa si lo hago al reves,
si recorro sacando los datos hasta encontrar */

void	ft_get_file_data(char **data, t_game *game)
{
	ft_view_data(data);
			printf("\nfloor %s\n", game->f_path);
			printf("\norte %s\n", game->no_path);
			printf("\nsur %s\n", game->so_path);
			printf("\noeste %s\n", game->we_path);
			printf("\neast %s\n", game->ea_path);
			printf("\nceiling%s\n", game->c_path);
	//	return (ft_perror("Error with data map"));

}
/*
con esta funcion extraigo todas las texturas 
y valores relacionados con el mapa
*/

void	ft_path_textures(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		ft_clean_path_textures(line);
		game->no_path = ft_strdup(line + 2);
		printf("\nholaNO: %s\n", game->no_path);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		ft_clean_path_textures(line);
		game->so_path = ft_strdup(line + 2);
		printf("\nholaSO: %s\n", game->so_path);
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		ft_clean_path_textures(line);
		game->we_path = ft_strdup(line + 2);
		printf("\nholaWE: %s\n", game->we_path);
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		ft_clean_path_textures(line);
		game->ea_path = ft_strdup(line + 2);
		printf("\nholaEA: %s\n", game->ea_path);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		ft_clean_path_textures(line);
		game->c_path = ft_strdup(line + 1);
		printf("\nholaC: %s\n", game->c_path);
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		ft_clean_path_textures(line);
		game->f_path = ft_strdup(line + 1);
		printf("\nholaF: %s\n", game->f_path);
	}
}
/*
esta funcion quitara los espacios y tabulaciones que hay antes 
de encontrar cualquier otro caracter
*/
void	ft_clean_path_textures(char *line)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strdup(line);
	if (!tmp)
		ft_perror("Error in strdup");
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		tmp[j] = line[i];
		i++;
		j++;
	}
	free(line);
	line = ft_calloc(j + 1, sizeof(char));
	if (!line)
		ft_perror("Error in calloc");
	ft_strlcpy(line, tmp, j);
	free(tmp);
}

//ft_clean_path_texture hace que la linea que entra en la funcion sea modificada y se le quite los espacios 
//y tabulaciones y guarda solo el path con el nombre de la textura al principio
