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
