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

void	ft_clean_data(t_game *game)
{
	char	**split_data;

	split_data = NULL;
	//split_data = ft_split(game->data, '\n');
	ft_free(game->data);
	game->data = split_data;
	ft_free(split_data);
}
