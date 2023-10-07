/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preDDA.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:21:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 18:57:14 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_pre(t_player *plyr, t_ray *ray, t_time *time)
{
	int	x;

	x = 0;
	plyr->pos_x = ;
	plyr->pos_y = ;
	plyr->dir_x = -1;
	plyr->dir_y = 0;
	plyr->plane_x = 0;
	plyr->plane_y = 0.66;
	time->fps = 0;
	time->old_fps = 0;
	while (x < WIN_WIDTH)
	{
		plyr->camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray->raydir_x = plyr->dir_x + plyr->plane_x * ray->camera_x;
		ray->raydir_y = plyr->dir_y + plyr->plane_y * ray->camera_x;
		x++;
	}
	ray->map_x = (int)plyr->pos_x;
	ray->map_y = (int)plyr->pos_y;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = abs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = abs(1 / ray->raydir_y);
	ray->hit_wall = 0;
	if (ray->raydir_x < 0)
	{
		plyr->step_x = -1;
		ray->sidedist_x = (plyr->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		plyr->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - plyr->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		plyr->step_y = -1;
		ray->sidedist_y = (plyr->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		plyr->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - plyr->pos_y) * ray->deltadist_y;
	}
}
