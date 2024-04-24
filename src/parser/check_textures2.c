#include "../../include/cub3d.h"

int	ft_check_c(char *data, t_game *game)
{
	int	i;

	i = 0;
	if (data && ft_strncmp(data, "C ", 2) == 0 && game->check_c != 0)
		return (1);
	else if (data && ft_strncmp(data, "C ", 2) == 0
		&& game->check_c == 0)
	{
		game->check_c = 1;
		ft_path_texture(data, game);
	}
	return (0);
}

// int	ft_check_f(char *data, t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	if (data && ft_strncmp(data, "F ", 2) == 0 && game->check_f != 0)
// 		return (1);
// 	else if (data && ft_strncmp(data, "F ", 2) == 0
// 		&& game->check_f == 0)
// 	{
// 		game->check_f = 1;
// 		ft_path_texture(data, game);
// 	}
// 	return (0);
// }

int	ft_check_line(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '1' || data[i] == '0')
			return (1);
		i++;
	}
	return (0);
}