#include "../include/cub3d.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(960, 600, "lobito malo 3D", false);
	if (!(game->mlx))
		return (1);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc != 2)
		ft_perror("Incorrect number of arguments");
	if (check_extension(argv[1]))
		ft_perror("Invalid file extension");
	ft_init_values(&game);
	game.data = ft_get_file(argv[1]);//tras esto tenemos en data tanto el mapa como las texturas
	ft_get_texture(game.data);
	//separar el mapa de las texturas y guardar el mapa en game.map que es mas grande que data
	game.map = ft_get_map(game.data);
	game.map_width_dd = ft_get_map_width_dd(game.map);
	while (game.map[i])
	{
		ft_putstr_fd(game.map[i], 1);
		write(1, "\n", 1);
		i++;
	}
	//init_game(&game);
	return (0);
}

void	ft_init_values(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->data = NULL;
	game->file_data = NULL;
	game->map_width_dd = 0;
}

char	**ft_get_map(char **data)
{
	int		i;
	char	**map;

	i = 0;
	while (data[i] && data[i][0] != '1')
		i++;
	map = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (data[i] && data[i][0] != '1')
	{
		map[i] = ft_strdup(data[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}