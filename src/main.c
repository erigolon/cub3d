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

void	init_mlx_struct(t_game *game)
{
	game->window_width = W_WIDTH;
	game->window_height = W_HEIGHT;
	game->map = malloc(5 * sizeof(char *));
	game->map[0] = ft_strdup("1111111  111");
	game->map[1] = ft_strdup("1000001  101");
	game->map[2] = ft_strdup("10P0001  111");
	game->map[3] = ft_strdup("1111111     ");
	game->map[4] = ft_strdup("");

}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_perror("Incorrect number of arguments");
	if (check_extension(argv[1]))
		ft_perror("Invalid file extension");
	init_mlx_struct(&game);
	if (init_game(&game))
		ft_perror("MLX no init");
	return (0);
}
