#include "../../include/cub3d.h"

int	check_extension(const char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'b' || fn[i - 1] != 'u'
		|| fn[i - 2] != 'c'
		|| fn[i - 3] != '.')
		return (1);
	return (0);
}

int	ft_different_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!((map[i][j] == 'N' || map[i][j] == 'S')
				|| (map[i][j] == 'E' || map[i][j] == 'W')
				|| (map[i][j] == '0') || (map[i][j] == '0')
				|| (map[i][j] == '2')))
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

/*
	Funcion que retorna el ancho de la matriz de la variable map length
*/
int	ft_get_map_width_dd(char **map)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > length)
			length = j;
		i++;
	}
	return (length);
}

int	ft_get_start_map(t_game *game, int last_line_saw)
{
	int		i;
	int		j;

	i = last_line_saw;
	while (game->data[i])
	{
		while (game->data[i][j] == ' ' || game->data[i][j] == '\t')
			j++;
		if (game->data[i][j] == '1' || game->data[i][j] == '0'
			|| game->data[i][j] == 'N' || game->data[i][j] == 'S'
			|| game->data[i][j] == 'W' || game->data[i][j] == 'E')
			return (i);
		i++;
	}
	return (0);
}

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
