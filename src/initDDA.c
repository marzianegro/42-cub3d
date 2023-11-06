/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initDDA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:21:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/06 11:25:30 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_plyr(t_map *map, t_player *plyr)
{
	plyr->pos_x = map->player[X];
	plyr->pos_y = map->player[Y];
	plyr->dir_x = -1; // not sure
	plyr->dir_y = 0; // not sure
	plyr->plane_x = 0;
	plyr->plane_y = 0.66;
}

void	ft_init_ray(t_player *plyr, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir_x = plyr->dir_x + plyr->plane_x * ray->camera_x;
	ray->dir_y = plyr->dir_y + plyr->plane_y * ray->camera_x;
	ray->pos_x = (int)plyr->pos_x;
	ray->pos_y = (int)plyr->pos_y;
}

// 1e30 is an arbitrarily chosen high enough number and can be set to infinity,
// if your programming language supports assigning that value
void	ft_deltadist(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	ft_step_sidedist(t_player *plyr, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		plyr->step_x = -1;
		ray->sidedist_x = (plyr->pos_x - ray->pos_x) * ray->deltadist_x;
	}
	else
	{
		plyr->step_x = 1;
		ray->sidedist_x = (ray->pos_x + 1.0 - plyr->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		plyr->step_y = -1;
		ray->sidedist_y = (plyr->pos_y - ray->pos_y) * ray->deltadist_y;
	}
	else
	{
		plyr->step_y = 1;
		ray->sidedist_y = (ray->pos_y + 1.0 - plyr->pos_y) * ray->deltadist_y;
	}
}

void	ft_init_dda(t_game *game, int x)
{
	ft_init_plyr(&game->map, &game->plyr);
	ft_init_ray(&game->plyr, &game->ray, x);
	ft_deltadist(&game->ray);
	game->ray.hit_wall = 0;
	ft_step_sidedist(&game->plyr, &game->ray);
}
