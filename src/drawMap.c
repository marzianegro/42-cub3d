/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:33 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 18:54:42 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_cf()
{
	
}

void	ft_draw_wall(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex)
{
	int			y;
	uint32_t	color;

	y = tex->wall_start;
	tex->step = 1.0 * tex->height / tex->wall_height;
	tex->pos = (tex->wall_start - SCREEN_HEIGHT / 2 + tex->wall_height / 2) * tex->step;
	while (y < tex->wall_end)
	{
		tex->y_coor = (int)tex->pos & (tex->height - 1);
		tex->pos += tex->step;
		color = tex[tex->num][tex->height * tex->y_coor + tex->x_coor];
		if (ray->side_wall == 1)
			color = (color >> 1) & 8355711;
		ft_my_pixelput();
		y++;
	}
}
