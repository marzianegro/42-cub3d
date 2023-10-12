/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:33 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 14:41:34 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_cf()
{
	
}

void	ft_draw_wall(t_game *game, int x)
{
	int			y;
	uint32_t	color;

	y = game->tex.wall_start;
	game->tex.step = 1.0 * game->tex.height / game->tex.wall_height;
	game->tex.pos = (game->tex.wall_start - SCREEN_HEIGHT / 2 + game->tex.wall_height / 2) * game->tex.step;
	while (y < game->tex.wall_end)
	{
		game->tex.y_coor = (int)game->tex.pos & (game->tex.height - 1);
		game->tex.pos += game->tex.step;
		color = tex[game->tex.num][game->tex.height * game->tex.y_coor + game->tex.x_coor];
		if (game->ray.side_wall == 1)
			color = (color >> 1) & 8355711;
		ft_pixel_put(game->data, x, y, color);
		y++;
	}
}
