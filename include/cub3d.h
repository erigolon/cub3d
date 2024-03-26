#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <unistd.h>

# define FALSE 1
# define TRUE 0

typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	char	**data;
	int		map_width_dd;
	int		map_height_dd;
}			t_game;

/*		main.c		*/
void	ft_init_values(t_game *game);
int		init_game(t_game *game);
/*		Utils		*/

int			ft_perror(const char *str);

/*		Parser		*/
int			check_extension(const char *fn);
/*		Map			*/
int			ft_num_col_file(int fd);
int			ft_size_file(char *path);
char		**ft_read_fd(char *path, int num_col);
void		ft_charge_file_data(char **map, int fd, int num_col);
char		**ft_get_file(char *path);

/*	 Map_utils		*/
int			ft_different_c(char **map);
int			ft_get_map_width_dd(char **map);

#endif