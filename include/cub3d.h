/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:47:00 by erigolon          #+#    #+#             */
/*   Updated: 2024/03/27 12:36:35 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# include <unistd.h>
# include <stdio.h>

# define W_WIDTH 1920
# define W_HEIGHT 1080

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

}			t_game;

/*		Utils		*/

int		ft_perror(const char *str);

/*		Parser		*/

int		check_extension(const char *fn);

/*		 Map 		*/

void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_map(t_game *game, t_images *images);

/*		 Move 		*/

void	ft_hook(void *param);

#endif