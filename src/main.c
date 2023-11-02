/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:24:57 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/02 12:31:37 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game		game;

	if (ac != 2)
		ft_error("invalid number of arguments");
	ft_check_ext(av);
	ft_init_vars();
	ft_mlx_init(&game);
	ft_init_map(&game, &game.map, av[1]);
	ft_check_map(&game.map);
	ft_mlx_start(&game);
}
