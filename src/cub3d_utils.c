#include "../include/cub3d.h"

int	ft_perror(const char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	ft_line_x(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = s;
	i = 0;
	while (i < n)
		c[i++] = 'x';
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
