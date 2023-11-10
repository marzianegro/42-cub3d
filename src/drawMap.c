/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:33 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 13:01:18 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= SCREEN_WIDTH || x <= 0 || y >= SCREEN_HEIGHT || y <= 0)
		return ;
	pxl = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)pxl = color;
}

void	ft_calc_cf_color(t_game *game)
{
	game->map.ceiling = (game->tex.cf_rgb[1][0] << 16)
		| (game->tex.cf_rgb[1][1] << 8) | game->tex.cf_rgb[1][2];
	game->map.floor = (game->tex.cf_rgb[0][0] << 16)
		| (game->tex.cf_rgb[0][1] << 8) | game->tex.cf_rgb[0][2];
}

int	ft_calc_tex_color(t_texture *tex)
{
	int	color;

	color = 0x0;
	if (tex->x_coor >= 0 && tex->x_coor < tex->width
		&& tex->y_coor >= 0 && tex->y_coor < tex->height)
		color = *(int *)(tex->spt[tex->num].addr + (4 * tex->width
					* (int)tex->y_coor) + (4 * (int)tex->x_coor));
	return (color);
}

void	ft_draw_cf(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	ft_calc_cf_color(game);
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < (SCREEN_HEIGHT / 2))
				ft_pixel_put(&game->data, x, y, game->map.ceiling);
			else
				ft_pixel_put(&game->data, x, y, game->map.floor);
			x++;
		}
		y++;
	}
}

/*	A loop in the y direction is requires to go through every pixel and
	determine which texel (texture pixel) of the texture should be used */
void	ft_draw_wall(t_game *game, int x)
{
	int	y;
	int	color;

	y = game->tex.wall_start;
	game->tex.step = 1.0 * game->tex.height / game->tex.wall_height;
	game->tex.pos = (game->tex.wall_start - SCREEN_HEIGHT / 2
			+ game->tex.wall_height / 2) * game->tex.step;
	while (y < game->tex.wall_end)
	{
		// we're masking with (game->tex.height - 1) in case of overflow
		game->tex.y_coor = (int)game->tex.pos & (game->tex.height - 1);
		game->tex.pos += game->tex.step;
		color = ft_calc_tex_color(&game->tex);
		ft_pixel_put(&game->data, x, y, color);
		y++;
	}
}
