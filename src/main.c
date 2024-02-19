/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:11 by erigolon          #+#    #+#             */
/*   Updated: 2024/02/19 17:31:52 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_perror(const char *str)
{
	printf("%s\n", str);
	return (1);
}

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

	(void)argv;
	if (argc != 2)
		return (ft_perror("Incorrect number of arguments"));
	init_game(&game);
	return (0);
}
