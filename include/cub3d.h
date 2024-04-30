#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/libft.h"
# include "cub3d_structs.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

/*		Defines			*/

# define FALSE 1
# define TRUE 0

# define W_WIDTH 1280
# define W_HEIGHT 720

/*		main.c		*/

int		init_game(t_game *game);
void	init_mlx_struct(t_game *game);
void	ft_start(t_game *game);

/*		Utils		*/

int		ft_perror(const char *str);
void	ft_line_x(void *s, size_t n);
void	ft_free(char **str);

/*		Parser		*/

int		check_extension(const char *fn);
int		ft_different_c(char **map);

/*		Colors*/

int		ft_trans_color(char *line);
int		ft_get_rgba(int r, int g, int b, int a);

/*		Data	*/

void	ft_init_values(t_game *game);
int		ft_all_info_extracted(t_game *game);
void	ft_path_texture(char *line, t_game *game);
int		ft_check_texture(t_game *game);
void	free_all(t_game *game);

/*check_textures*/
/*
int		ft_check_no(char *data, t_game *game);
int		ft_check_so(char *data, t_game *game);
int		ft_check_we(char *data, t_game *game);
int		ft_check_ea(char *data, t_game *game);
int		ft_check_c(char *data, t_game *game);
int		ft_check_f(char *data, t_game *game);
*/
int		ft_check_line(char *data);

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
void	ft_view_data(char **map);
void	ft_clean_data(t_game *game);

/*		Move		*/

void	ft_hook(void *param);

/*		Draw		*/

void	calculate_n_draw(t_game *game);

/*clean data*/
int		ft_count_valid_lines(char **data);
char	**ft_create_clean_data_array(int new_line_count);
char	**ft_copy_valid_lines(char **data, char **new_data);
int		ft_is_valid_line(char *line);
char	**ft_clean_data_copy(char **data);

/*path*/

void	ft_path_textures(char *line, t_game *game);
void	ft_clean_path_textures(char *line);
void	ft_extract_path(char **cpy_data, t_game *game);

//new fuction
void		ft_get_file_data(char **data, t_game *game);

void	ft_check_lines_map(t_game *game, char **data);
int		ft_map_with_empty_lines(char **data, int i);
int		ft_line_empty(char *str);
int		ft_no_found_path(char *data);
int	ft_line_empty_2(char *str);
void ft_check_empty_lines_map(char **data, int start_map);


#endif