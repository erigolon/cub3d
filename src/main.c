/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:11 by erigolon          #+#    #+#             */
/*   Updated: 2024/02/20 10:40:02 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_perror("Incorrect number of arguments");
	if (check_extension(argv[1]))
		ft_perror("Invalid file extension");
	init_game(&game);
	return (0);
}
