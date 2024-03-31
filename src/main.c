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

void	ft_start(t_game *game)
{
	int		last_line_saw;
	int		map_start;

	map_start = 0;
	last_line_saw = 0;
	last_line_saw = ft_get_file_data(game->data, game);
	if (ft_check_texture(game))
		ft_perror("Error in textures");
	map_start = ft_get_start_map(game, last_line_saw);
	if (map_start == 0)
		ft_perror("No have data map");
	ft_get_map(game, (game->height_data) - map_start, map_start);
	game->map_height_dd = game->height_data - map_start;
	game->map_width_dd = ft_get_map_width_dd(game->map);
	if (ft_different_c(game->map))
		ft_perror("Error in map");
	ft_map_rectangle(game);
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
	game.data = ft_get_file(argv[1], &game);
	ft_start(&game);
	while (game.map[i])
	{
		ft_putstr_fd(game.map[i], 1);
		write(1, "\n", 1);
		i++;
	}
	init_game(&game);
	return (0);
}
