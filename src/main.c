#include "../include/cub3d.h"

static void	ft_leaks(void)
{
	system("leaks -q cub3D");
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init(game->window_width, game->window_height,
			"Lobito malo 3D", false);
	if (!(game->mlx))
		return (1);
	game->image = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	calculate_n_draw(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
} 

void	ft_start(t_game *game)
{
	int		last_line_saw;
	int		map_start;
	char	**copy_data;

	map_start = 0;
	last_line_saw = 0;
	ft_check_lines_map(game, game->data);//ubica principio del mapa
	ft_check_empty_lines_map(game->data, game->start_map);//comprueba que no tenga saltos de linea entre medio del mapa
	copy_data = ft_clean_data_copy(game->data);
	//write(1, "\ntpe\n", 5);
	printf("\nfloor %s\n", game->f_path);
	printf("\norte %s\n", game->no_path);
	printf("\nsur %s\n", game->so_path);
	printf("\noeste %s\n", game->we_path);
	printf("\neast %s\n", game->ea_path);
	printf("\nceiling%s\n", game->c_path);
	ft_extract_path(copy_data, game);
	//hasta aqui todo ok
	//last_line_saw = ft_get_file_data(game->data, game);
	ft_get_file_data(game->data, game);
	if (game->data[last_line_saw] == NULL)
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
	write(1, "pepe", 4);
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(ft_leaks);
	if (argc != 2)
		ft_perror("Incorrect number of arguments");
	if (check_extension(argv[1]))
		ft_perror("Invalid file extension");
	ft_init_values(&game);
	game.data = ft_get_file(argv[1], &game);//obten toda la data
	ft_start(&game);
	/*init_mlx_struct(&game);
	if (init_game(&game))
		ft_perror("MLX no init");
	free_all(&game);*/
	return (0);
}
void ft_check_empty_lines_map(char **data, int start_map)
{
	int i;
	int gay;

	gay = 0;
	i = start_map;
	while (data[i])
	{
		if (ft_line_empty(data[i]))
			gay = 1;
		if (!ft_line_empty(data[i]) && gay == 1)
			ft_perror("Error in map");
		i++;
	}
}