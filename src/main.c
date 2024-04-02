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
	ft_replace_sp_tab(game);
	if (ft_map_open(game))
		ft_perror("Error map open");
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
	while (game.new_map[i])
	{
		printf("%s\n", game.new_map[i]);
		i++;
	}
	//printf("%s\n", game.new_map[6]);
	// init_game(&game);
	return (0);
}

/*
esta funcion se encarga de comprobar si todo el mapa esta rodeado de muros
es decir de caracteres '1', al poder haber un espacio en blanco en el mapa
he de comprobar todas las posiciones que rodean a un caracter valido, desde el 
primer 0 o el valor de la posicion de la orientacion del jugador
por tanto previamente rodee el mapa con carcateres 'x' para poder comprobar
si el mapa esta rodeado de muros, es decir que si partiendo de cualqier 0 o N,S,E,W
no puede llegar a una 'x' si ocurre el mapa estaria mal
*/
int	ft_map_open(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->new_map[i])
	{
		j = 0;
		while (game->new_map[i][j])
		{
			if (game->new_map[i][j] == '0' || game->new_map[i][j] == 'N'
				|| game->new_map[i][j] == 'S' || game->new_map[i][j] == 'E'
				|| game->new_map[i][j] == 'W')
			{
				if (ft_check_open(game, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}