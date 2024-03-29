/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:47:00 by erigolon          #+#    #+#             */
/*   Updated: 2024/02/20 10:36:03 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# include <unistd.h>
# include <stdio.h>


typedef struct s_game
{
	mlx_t	*mlx;

}			t_game;


/*		Utils		*/

int	ft_perror(const char *str);


/*		Parser		*/

int	check_extension(const char *fn);

#endif