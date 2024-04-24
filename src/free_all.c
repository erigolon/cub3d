#include "../include/cub3d.h"

static void	free_textu(t_game *game)
{
	mlx_delete_texture(game->textu->no_textu);
	mlx_delete_texture(game->textu->so_textu);
	mlx_delete_texture(game->textu->ea_textu);
	mlx_delete_texture(game->textu->we_textu);
	free(game->textu);
}

static void	free_game(t_game *game)
{
	ft_free(game->map);
	ft_free(game->new_map);
	free(game->no_path);
	free(game->so_path);
	free(game->we_path);
	free(game->ea_path);
	free(game->c_path);
	free(game->f_path);
}

void	free_all(t_game *game)
{
	if (game->textu)
		free_textu(game);
	if (game->player)
		free(game->player);
	if (game->raycast)
		free(game->raycast);
	if (game)
		free_game(game);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}