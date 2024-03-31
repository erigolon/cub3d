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
	char	**file_data;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*c_path;
	char	*f_path;
	int		height_data;
}			t_game;

/*		main.c		*/
void	ft_init_values(t_game *game);
int		init_game(t_game *game);
/*		Utils		*/

int			ft_perror(const char *str);

/*		Parser		*/
int			check_extension(const char *fn);

/*		Data_utils	*/
void		ft_init_values(t_game *game);
int			ft_all_info_extracted(t_game *game);
int			ft_get_file_data(char **data, t_game *game);
void		ft_path_texture(char *line, t_game *game);
int			ft_check_texture(t_game *game);

/*		Map			*/
int			ft_num_col_file(int fd);
int			ft_size_file(char *path);
char		**ft_read_fd(char *path, int num_col);
void		ft_charge_file_data(char **map, int fd, int num_col);
char		**ft_get_file(char *path, t_game *game);

/*	 Map_utils		*/
int			ft_different_c(char **map);
int			ft_get_map_width_dd(char **map);

int	ft_get_start_map(t_game *game, int last_line_saw);
void	ft_get_map(t_game *game, int tam_map, int start_map);

#endif