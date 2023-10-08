/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawWalls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:00:26 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:24 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_perpwalldist(t_ray *ray)
{
	if (ray->side_wall == 0)
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
}

void	ft_wall_calcs(t_player *plyr, t_ray *ray, t_texture *tex)
{
	ft_perpwalldist(ray);
	tex->wall_height = (int)(WIN_HEIGHT / ray->perpwalldist);
	tex->wall_start = -tex->wall_height / 2 + WIN_HEIGHT / 2;
	if (tex->wall_start < 0)
		tex->wall_start = 0;
	tex->wall_end = tex->wall_height / 2 + WIN_HEIGHT / 2;
	if (tex->wall_end >= WIN_HEIGHT)
		tex->wall_end = WIN_HEIGHT - 1;
	if (ray->side_wall == 0)
		tex->wall_x = plyr->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		tex->wall_x = plyr->pos_x + ray->perpwalldist * ray->raydir_x;
	tex->wall_x -= floor((tex->wall_x));
	tex->coor_x = int(tex->wall_x * double(tex->width));
	if (ray->side_wall == 0 && ray->raydir_x > 0 ||
		ray->side_wall == 1 && ray->raydir_y < 0)
		tex->coor_x = tex->width - tex->coor_x - 1;
}
