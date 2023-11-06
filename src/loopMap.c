/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/06 16:30:11 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* the while loop goes through every x, so there isn’t a calculation for every
	pixel of the screen, but for every vertical stripe, which isn’t
	much at all */
int	ft_redrawinloop(t_game *game)
{
	int	x;

	x = 0;
	ft_draw_cf(game);
	while (x < SCREEN_WIDTH)
	{
		ft_init_dda(game, x);
		ft_dda(&game->map, &game->plyr, &game->ray, &game->tex);
		ft_calc_wall(game);
		ft_draw_wall(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->data.img, 0, 0);
	return (0);
}
