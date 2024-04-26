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

int	ft_check_all_extracted(t_game *game)
{
	if (game->no_path && game->so_path && game->we_path
		&& game->ea_path && game->c_path && game->f_path)
	{
/*
		printf("NO:%s\n", game->no_path);
		printf("SO:%s\n", game->so_path);
		printf("WE:%s\n", game->we_path);
		printf("EA:%s\n", game->ea_path);
		printf("C:%s\n", game->c_path);
		printf("F:%s\n", game->f_path);
*/
		return (0);
	}
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

	i = 0;
	while (cpy_data[i])
	{
		if (cpy_data[i] && ft_strncmp(cpy_data[i], "NO ", 3) == 0)
		{
			if (game->no_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data path");
		}
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "SO ", 3) == 0)
		{
			if (game->so_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data path");
		}
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "WE ", 3) == 0)
		{
			if (game->we_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data path");
		}
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "EA ", 3) == 0)
		{
			if (game->ea_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data path");
		}
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "C ", 2) == 0)
		{
			if (game->c_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data path");
		}
		else if (cpy_data[i] && ft_strncmp(cpy_data[i], "F ", 2) == 0)
		{
			if (game->f_path == NULL)
				ft_path_textures(cpy_data[i], game);
			else
				ft_perror("Error in data path");
		}
		i++;
		if (ft_check_all_extracted(game) == 1 && ft_no_found_path(cpy_data[i]) == 1)
			ft_perror("Errooooor in data path");
	}
}

int	ft_no_found_path(char *data)
{
	if (data && ft_strncmp(data, "NO", 2) != 0
		&& ft_strncmp(data, "SO", 2) != 0
		&& ft_strncmp(data, "WE", 2) != 0
		&& ft_strncmp(data, "EA", 2) != 0
		&& ft_strncmp(data, "C", 1) != 0
		&& ft_strncmp(data, "F", 1) != 0)
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

void	ft_path_textures(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		ft_clean_path_textures(line);
		game->no_path = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		ft_clean_path_textures(line);
		game->so_path = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		ft_clean_path_textures(line);
		game->we_path = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		ft_clean_path_textures(line);
		game->ea_path = ft_strdup(line + 2);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		ft_clean_path_textures(line);
		game->c_path = ft_strdup(line + 1);
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		ft_clean_path_textures(line);
		game->f_path = ft_strdup(line + 1);
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

	j = 0;
	i = 0;
	tmp = ft_strdup(line);
	if (!tmp)
		ft_perror("Error in strdup");
	while (line[i])
	{
		while (line && (line[i] == ' ' || line[i] == '\t'))
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
