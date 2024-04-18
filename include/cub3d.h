#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <unistd.h>

/*		Defines			*/

# define FALSE 1
# define TRUE 0

# define W_WIDTH 1920
# define W_HEIGHT 1080

/*		Structs			*/

typedef struct s_textures
{
	mlx_texture_t		*wall_2d;
	mlx_texture_t		*floor_2d;
	mlx_texture_t		*my_guy;
}			t_textures;

typedef struct s_images
{
	mlx_image_t			*wall_2d;
	mlx_image_t			*floor_2d;
	mlx_image_t			*my_guy;
}			t_images;

typedef struct s_game
{
	mlx_t				*mlx;
	struct s_textures	*textu;
	struct s_images		*imag;
	int					window_width;
	int					window_height;
	char				**map;
	char				**new_map;
	char				**data;
	int					height_data;
	int					map_width_dd;
	int					map_height_dd;
	char				**file_data;
	struct s_info_textu	i_textu;
	int					color_floor;
	int					color_ceiling;
}			t_game;


typedef struct s_info_textu
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*c_path;
	char	*f_path;
	int 	check_no;
	int 	check_so;
	int 	check_we;
	int 	check_ea;
	int 	check_c;
	int 	check_f;
}			t_info_textu;

/*		main.c		*/

int		init_game(t_game *game);
void	ft_start(t_game *game);

/*		Utils		*/

int		ft_perror(const char *str);
void	ft_line_x(void *s, size_t n);
void	ft_free(char **map);

/*		Parser		*/

int		check_extension(const char *fn);
int		ft_different_c(char **map);

/*		Colors		*/
int		ft_trans_color(char *line);
int		ft_get_rgba(int r, int g, int b, int a);

/*		Data	*/

void	ft_init_values(t_game *game);
int		ft_all_info_extracted(t_game *game);
int		ft_get_file_data(char **data, t_game *game);
void	ft_path_texture(char *line, t_game *game);
int		ft_check_texture(t_game *game);

/*		extarct data	*/

char	**ft_get_file(char *path, t_game *game);
int		ft_num_row_file(int fd);
int		ft_size_file(char *path);
char	**ft_read_fd(char *path, int num_col);
void	ft_charge_file_data(char **map, int fd, int num_col);


/*	 	Map			*/

int		ft_get_map_width_dd(char **map);
int		ft_get_start_map(t_game *game, int last_line_saw);
void	ft_get_map(t_game *game, int tam_map, int start_map);
void	ft_map_rectangle(t_game *game);
void	ft_replace_sp_tab(t_game *game);

void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_map(t_game *game, t_images *images);

/*		Move		*/

void	ft_hook(void *param);


#endif