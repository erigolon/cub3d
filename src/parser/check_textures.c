#include "../../include/cub3d.h"

void	ft_check_lines_map(t_game *game, char **data)
{
	int	i;

	i = 0;
	//si existe es porque esta full vacia.
	while (data[i])
	{
		if (ft_line_empty(data[i]))//deberia dar 1 si esta vacia y entrar
			i++;
		else if (ft_line_empty_2(data[i]))
			i++;
		else
			break ;
		i++;
	}
	game->start_map = i;
}
//funcion que comprueba que la linea no esta vacia desdpues de encontrar el mapa

int	ft_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
		i++;
	if (line[i])
		return (0);
	return (1);
}

int	ft_line_empty_2(char *str)
{
	int	i;

	i = 0;
//	write(1, "\nPAPA\n", 6);
	while (str[i] && ((str[i] == ' ' || str[i] == '\t')))
		i++;
	if (str[i] && ft_no_found_path(str + i))
		return (1);
	return (0);
}

int	ft_no_found_path(char *data)
{
	if (ft_strncmp(data, "NO", 2) == 0
		|| ft_strncmp(data, "SO", 2) == 0
		|| ft_strncmp(data, "WE", 2) == 0
		|| ft_strncmp(data, "EA", 2) == 0
		|| ft_strncmp(data, "C", 1) == 0
		|| ft_strncmp(data, "F", 1) == 0)
		{
			//write(1, "\npapa\n", 6);
			return (1);
		}
	return (0);
}

int	ft_map_with_empty_lines(char **data, int i)
{
	while (data[i])
	{
		if (!ft_line_empty(data[i]))
			return (1);
		i++;
	}
	return (0);
}


//si es distinto de ft_empty_line y de los posibles path, entonces es el start del mapa