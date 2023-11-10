/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/09 20:57:46 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clear_img(t_game *game)
{
	if (game->data.img)
		mlx_destroy_image(game->mlx_ptr, game->data.img);
	game->data.img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bpp, &game->data.line_len,
			&game->data.endian);
}

/*	The ray-casting loop is a while loop goes through every x, so the
	calculation won't be done for every pixel of the screen but for every
	vertical stripe, which isn’t much at all */
int	ft_redrawinloop(t_game *game)
{
	int	x;

	x = 0;
	ft_clear_img(game);
	ft_draw_cf(game);
	while (x < SCREEN_WIDTH)
	{
		ft_init_dda(game, x);
		ft_dda(&game->map, &game->plyr, &game->ray, &game->tex);
		/* After the DDA is done, you have to calculate the distance of the ray
			from the wall, so that you can calculate how high the wall has to be drawn */
		ft_calc_wall(game);
		ft_draw_wall(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->data.img, 0, 0);
	// exit(0);
	return (0);
}
