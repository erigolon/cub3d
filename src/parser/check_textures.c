#include "../../include/cub3d.h"

int	ft_check_no(char *data, t_game *game)
{
	int	i;

	i = 0;
	if (data && ft_strncmp(data, "NO ./", 5) == 0 && game->check_no != 0)
		return (1);
	else if (data && ft_strncmp(data, "NO ./", 5) == 0
		&& game->check_no == 0)
	{
		game->check_no = 1;
		ft_path_texture(data, game);
	}
	return (0);
}

int	ft_check_so(char *data, t_game *game)
{
	int	i;

	i = 0;
	if (data && ft_strncmp(data, "SO ./", 5) == 0 && game->check_so != 0)
		return (1);
	else if (data && ft_strncmp(data, "SO ./", 5) == 0
		&& game->check_so == 0)
	{
		game->check_so = 1;
		ft_path_texture(data, game);
	}
	return (0);
}

int	ft_check_ea(char *data, t_game *game)
{
	int	i;

	i = 0;
	if (data && ft_strncmp(data, "EA ./", 5) == 0 && game->check_ea != 0)
		return (1);
	else if (data && ft_strncmp(data, "EA ./", 5) == 0
		&& game->check_ea == 0)
	{
		game->check_ea = 1;
		ft_path_texture(data, game);
	}
	return (0);
}

int	ft_check_we(char *data, t_game *game)
{
	int	i;

	i = 0;
	if (data && ft_strncmp(data, "WE ./", 5) == 0 && game->check_we != 0)
		return (1);
	else if (data && ft_strncmp(data, "WE ./", 5) == 0
		&& game->check_we == 0)
	{
		game->check_we = 1;
		ft_path_texture(data, game);
	}
	return (0);
}

int	ft_check_f(char *data, t_game *game)
{
	int	i;

	i = 0;

	if (data && ft_strncmp(data, "F ", 2) == 0 && game->check_f != 0)
		return (1);
	else if (data && ft_strncmp(data, "F ", 2) == 0
		&& game->check_f == 0)
	{
		game->check_f = 1;
		ft_path_texture(data, game);
	}
	return (0);
}