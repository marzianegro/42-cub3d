/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:24:57 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/24 17:31:21 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_texture	tex;

	(void)tex;
	if (ac != 2)
		ft_error("invalid number of arguments");
	ft_check_ext(av);
	// ft_init_variab(&game);
	ft_init_map(&game, &game.map, av[1]);
	ft_check_map(av, &game.map);
	ft_mlxinit(&game, &game.map);
}
