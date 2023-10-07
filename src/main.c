/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:24:57 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 15:56:28 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_end(t_game *game, int n)
{
	if (n == 3)
		ft_printf("\nYou've made it out of the maze! Congrats!"
			"\033[1;92myou win\033[0;39m! :)\n");
	ft_unload_all(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	// free the map
	free(game->mlx_ptr);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

    if (ac != 2)
		ft_error("invalid number of arguments!");
	ft_check_format(ac, av);
	ft_init_variab(&game);
	ft_init_map(&game, av[1]);
	ft_controllo mappa
	ft_inizio gioc
}
