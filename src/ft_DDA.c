/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DDA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:00:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 19:04:38 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Digital Differential Analysis
void	ft_dda(t_player *plyr, t_ray *ray, t_time *time,
			t_texture *tex, t_map *map)
{
	while (ray->hit_wall == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x = plyr->step_x;
			ray->side_wall = 0;
		}
		else
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_y += plyr->step_y;
			ray->side_wall = 0;
		}
		if (map->map[ray->map_x][ray->map_y])
			ray->side_wall = 1;
	}
	if (ray->side_wall == 0)
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
	tex->line_height = (int)(h / ray->perpwalldist);
	tex->line_start = -tex->line_height / 2 + WIN_HEIGHT / 2;
	if (tex->line_start < 0)
		tex->line_start = 0;
	tex->line_end = tex->line_height / 2 + WIN_HEIGHT / 2;
	if (tex->line_end >= WIN_HEIGHT)
		tex->line_end = WIN_HEIGHT - 1;
	time->old_fps = time->fps;
	time->fps = gettimeofday();
	time->frame_time = (time->fps - time->old_fps) / 1000.0;
	printf("%d", 1.0 / time->frame_time);
	redraw();
	cls();
	time->move_speed = time->frame_time * 5.0;
	time->rot_speed = time->frame_time * 3.0;
}
