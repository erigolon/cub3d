#include "../../include/cub3d.h"

int	ft_check_no(char *data, t_game *game)
{
	int	i;

	i = 0;
	if (data && ft_strncmp(data, "NO ./", 5) == 0
		&& game->i_textu.check_no != 0)
		return (1);
	else (data && ft_strncmp(data, "NO ./", 5) == 0
			&& game->i_textu.check_no == 0)
	{
		game->i_textu.check_no = 1;
		ft_path_texture(data, game);
	}
	return (0);
}
