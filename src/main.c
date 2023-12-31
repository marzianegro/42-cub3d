/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:24:57 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/17 16:27:46 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game		game;

	ft_init_vars(&game);
	ft_init_err(&game);
	if (ac != 2)
		ft_error(NULL, "invalid number of arguments", NULL);
	ft_check_ext(av);
	ft_init_map(&game, &game.map, av[1]);
	ft_check_map(&game, &game.map);
	ft_mlx_init(&game);
	ft_mlx_start(&game);
}
