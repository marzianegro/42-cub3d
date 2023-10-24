/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:33 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/24 17:34:11 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_pixel_put(t_data *data, int x, int y, int color)
{
    char    *pxl;
    
    pxl = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int*)pxl = color;
}

void    ft_draw_cf(t_game *game)
{
    int y;
    int x;
    int color;
	
	y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            if (y < (SCREEN_HEIGHT / 2))
                ft_pixel_put(&game->data, x, y, game->tex.ceiling_rgb);
            else
                ft_pixel_put(&game->data, x, y, game->tex.floor_rgb);
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
	game->tex.pos = (game->tex.wall_start - SCREEN_HEIGHT / 2 + game->tex.wall_height / 2) * game->tex.step;
	while (y < game->tex.wall_end)
	{
		game->tex.y_coor = (int)game->tex.pos & (game->tex.height - 1);
		game->tex.pos += game->tex.step;
		color = game->tex[game->tex.spt[0].img][game->tex.height * game->tex.y_coor + game->tex.x_coor];
		if (game->ray.side_wall == 1)
			color = (color >> 1) & 8355711;
		ft_pixel_put(&game->data, x, y, color);
		y++;
	}
}
