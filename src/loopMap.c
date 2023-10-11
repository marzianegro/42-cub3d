/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 12:15:47 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// the while loop goes through every x, so there isn’t a calculation for every
// pixel of the screen, but for every vertical stripe, which isn’t much at all
int	ft_redrawinloop(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_init_dda(game);
		ft_dda(game->map, game->plyr, game->ray);
		ft_wall_calcs(game->plyr, game->ray, game->tex);
		ft_calc_time();
		ft_calc_tex();
		x++;
	}
	return (0);
}
