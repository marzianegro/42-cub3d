/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/07 15:46:07 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* The while loop goes through every x, so the calculation won't be for every
	pixel of the screen but for every vertical stripe, which isn’t
	much at all */
int	ft_redrawinloop(t_game *game)
{
	int	x;

	x = 0;
	// mlx_destroy_image(game->mlx_ptr, game->data.img);
	// game->data.img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	// game->data.addr = mlx_get_data_addr(game->data.img,
	// 		&game->data.bpp, &game->data.line_len,
	// 		&game->data.endian);
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
	// now the buffer (img) still has to be drawn and, after that, cleared
	return (0);
}
