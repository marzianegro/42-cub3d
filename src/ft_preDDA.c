/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preDDA.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:21:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:48 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_plyr(t_player *plyr)
{
	plyr->pos_x = ;
	plyr->pos_y = ;
	plyr->dir_x = -1;
	plyr->dir_y = 0;
	plyr->plane_x = 0;
	plyr->plane_y = 0.66;
	plyr->camera_x = 2 * x / (double)WIN_WIDTH - 1;
}

void	ft_init_ray(t_ray *ray)
{
	ray->raydir_x = plyr->dir_x + plyr->plane_x * ray->camera_x;
	ray->raydir_y = plyr->dir_y + plyr->plane_y * ray->camera_x;
	ray->map_x = (int)plyr->pos_x;
	ray->map_y = (int)plyr->pos_y;
}

void	ft_deltadist(t_player *plyr, t_ray *ray)
{
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = abs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
}


void	ft_step_sidedist(t_player *plyr, t_ray *ray)
{
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

void	ft_init_dda(t_game *game)
{
	ft_init_plyr(game->plyr);
	ft_init_ray(game->ray);
	ft_deltadist(game->plyr, game->ray);
	ft_step_sidedist(game->plyr, game->ray);
	ray->hit_wall = 0;
}
