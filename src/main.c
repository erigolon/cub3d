#include "../include/cub3d.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->window_width, game->window_height,
			"Lobito malo 3D", false);
	if (!(game->mlx))
		return (1);
	get_textures(game);
	get_images(game);
	draw_map(game, game->imag);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->textu);
	free(game->imag);
	return (0);
}

void	ft_start(t_game *game)
{
	int		last_line_saw;
	int		map_start;

	map_start = 0;
	last_line_saw = 0;
	last_line_saw = ft_get_file_data(game->data, game);
	if(game->data[last_line_saw] == NULL)
		ft_perror("No have data map");
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
	game->color_floor = ft_trans_color(game->f_path);
	game->color_ceiling = ft_trans_color(game->c_path);
}

void	init_mlx_struct(t_game *game)
{
	game->window_width = W_WIDTH;
	game->window_height = W_HEIGHT;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (argc != 2)
		ft_perror("Incorrect number of arguments");
	if (check_extension(argv[1]))
		ft_perror("Invalid file extension");
	ft_init_values(&game);
	game.data = ft_get_file(argv[1], &game);
	ft_start(&game);
	i = 0;
	while (game.map[i])
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	init_mlx_struct(&game);
	if (init_game(&game))
		ft_perror("MLX no init");
	return (0);
}