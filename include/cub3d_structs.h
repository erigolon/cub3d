#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include "cub3d.h"

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				angle;
}			t_player;

typedef struct s_textures
{
	mlx_texture_t		*no_textu;
	mlx_texture_t		*so_textu;
	mlx_texture_t		*we_textu;
	mlx_texture_t		*ea_textu;
}			t_textures;

typedef struct s_raycast
{
	double				dist;
	mlx_texture_t		*texture;
	double				angle;
}			t_raycast;

typedef struct s_game
{
	mlx_t				*mlx;
	struct s_player		*player;
	struct s_textures	*textu;
	struct s_raycast	*raycast;
	mlx_image_t			*image;
	int					window_width;
	int					window_height;
	char				**map;
	char				**new_map;
	char				**data;
	double				pov;
	int					map_width_dd;
	int					map_height_dd;
	char				**file_data;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*c_path;
	char				*f_path;
	int					color_floor;
	int					color_ceiling;
	int					height_data;
}			t_game;

#endif