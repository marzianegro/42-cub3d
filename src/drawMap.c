/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:33 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/07 16:29:43 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pxl;

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

	color = *(int *)(tex->spt[tex->num].addr + (tex->height
				* (int)tex->y_coor + (int)tex->x_coor));
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
		game->tex.y_coor = (int)game->tex.pos & (game->tex.height - 1);
		game->tex.pos += game->tex.step;
		color = ft_calc_tex_color(&game->tex);
		ft_pixel_put(&game->data, x, y, color);
		y++;
	}
}
