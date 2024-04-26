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
	ft_view_data(game->data);
	printf("\n\n");
	copy_data = ft_clean_data_copy(game->data);
	ft_view_data(copy_data);
	ft_free(game->data);
	ft_extract_path(copy_data, game);
/*
	printf("NO: %s\n", game->no_path);
	printf("SO: %s\n", game->so_path);
	printf("WE: %s\n", game->we_path);
	printf("EA: %s\n", game->ea_path);
	printf("C: %s\n", game->c_path);
	printf("F: %s\n", game->f_path);
*/
	//ft_clean_data(game);
	//ft_view_map(game->data);
	/*last_line_saw = ft_get_file_data(game->data, game);
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
	game->color_ceiling = ft_trans_color(game->c_path);*/
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
	game.data = ft_get_file(argv[1], &game);//hasta aqui todo bien
	ft_start(&game);
	/*init_mlx_struct(&game);
	if (init_game(&game))
		ft_perror("MLX no init");
	free_all(&game);*/
	return (0);
}
