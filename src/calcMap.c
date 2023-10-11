/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:00:26 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 18:56:10 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* This is done after the DDA has ended, as we have to calculate the distance
	of the ray from the wall, so that we can calculate how high the wall
	has to be drawn */

void	ft_cf_deets()
{
	
}

/* We don't use the Euclidean distance from the point representing the player,
	but the distance from the camera plane (or, the distance from the point,
	projected in the camera direction, to the player), to avoid the fish-eye
	effect, which would make all the walls become rounded and make us sick
	if we rotated. It’s also easier to calculate this perpendicular distance
	rather than the real distance, because we don’t even need to know the
	exact location where the wall was hit */
void	ft_perpwalldist(t_ray *ray)
{
	if (ray->side_wall == 0)
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
}

void	ft_wall_deets(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex)
{
	// calculate the lowest and highest pixels to fill in the current srtipe
	tex->wall_height = (int)(SCREEN_HEIGHT / ray->perpwalldist);
	tex->wall_start = -tex->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (tex->wall_start < 0)
		tex->wall_start = 0;
	tex->wall_end = tex->wall_height / 2 + SCREEN_HEIGHT / 2;
	if (tex->wall_end >= SCREEN_HEIGHT)
		tex->wall_end = SCREEN_HEIGHT - 1;
	// by subtracting 1 from it, we're able to use texture 0
	tex->num = map->map[ray->pos_y][ray->pos_x] - 1;
	if (ray->side_wall == 0)
		tex->wall_x = plyr->pos_y + ray->perpwalldist * ray->dir_y;
	else
		tex->wall_x = plyr->pos_x + ray->perpwalldist * ray->dir_x;
	tex->wall_x -= floor((tex->wall_x));
	tex->x_coor = (int)(tex->wall_x * double(tex->width));
	if (ray->side_wall == 0 && ray->dir_x > 0 ||
		ray->side_wall == 1 && ray->dir_y < 0)
		tex->x_coor = tex->width - tex->x_coor - 1;
}

void	ft_calc_wall(t_game *game)
{
	ft_perpwalldist(game->ray);
	ft_wall_deets(game->map, game->plyr, game->ray, game->tex);
}
