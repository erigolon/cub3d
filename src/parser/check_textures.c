#include "../../include/cub3d.h"

void	ft_check_lines_map(char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (ft_map_empty(data[i]))
				ft_perror("Error in map");
			if (data[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (data[i][j] == '\0')
			ft_perror("Error in map");
		i++;
	}
}
//funcion que comprueba que la linea no esta vacia desdpues de encontrar el mapa

int	ft_map_empty(char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i])
	{
		j = 0;
		if (data[i][j] == '\0' || data[i][j] == '\n')
			return (1);
	}
}

int	ft_line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		i++;
	if (str[i])
		return (1);
	return (0);
}

void	ft_check_map_spaces(char **data, int i)
{
	while (data[i] != NULL)
	{
		if (!ft_str_empty(data[i]))
			ft_perror("Cannot be new line between content map");
		if (ft_str_wrong_map(data[i]))
		{
			ft_error_line("Line cannot be there", data[i]);
		}
		i++;
	}
}

int	ft_str_wrong_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' '
			&& str[i] != '\n' && str[i] != '\t' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

void	ft_get_identifiers(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->data[i] != NULL && j < 6)
	{
		if (ft_str_empty(game->data[i]))
		{
			ft_get_all(game, game->data[i]);
			j++;
		}
		i++;
	}
	while (game->data[i] != NULL && !ft_str_empty(game->data[i]))
		i++;
	game->start = i;
	ft_check_map_spaces(game, i);
}