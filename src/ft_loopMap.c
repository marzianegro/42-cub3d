/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:46 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_redrawinloop(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_init_dda(game);
		ft_dda(game->map, game->plyr, game->ray);
		ft_wall_calcs(game->plyr, game->ray, game->tex);
		ft_draw_map();
		x++;
	}
	return (0);
}
