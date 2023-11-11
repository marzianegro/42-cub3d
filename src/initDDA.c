/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initDDA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:21:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/11 13:46:33 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* I'm not really sure what to put for plyr->dir_x and plyr->dir_y */
void	ft_init_plyr(t_map *map, t_player *plyr)
{
	// Position vector of the player
	plyr->pos_x = map->player[X];
	plyr->pos_y = map->player[Y];
	// Direction of the player
	plyr->dir_x = -1;
	plyr->dir_y = 0;
	// Camera plane of the player
	plyr->plane_x = 0;
	plyr->plane_y = 0.66;
}

void	ft_init_ray(t_player *plyr, t_ray *ray, int x)
{
	/*	ray->camera_x is the x coordinate of the camera plane that the current x
		coordinate of the screen represents, and it's calculated this way so
		the right side of the screen gets coordinate 1, the centre 0, and
		the left -1 */
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	// Sum of the player's direction vector and a part of the plane vector
	ray->dir_x = plyr->dir_x + plyr->plane_x * ray->camera_x;
	ray->dir_y = plyr->dir_y + plyr->plane_y * ray->camera_x;
	// The ray starts at the player's position
	ray->pos_x = (int)plyr->pos_x;
	ray->pos_y = (int)plyr->pos_y;
}

/*	ray->deltadist_x and ray->deltadist_y are the distance the ray has to
	travel to go from one x or y side to the next */
void	ft_deltadist(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->dir_x);
	if (ray->dir_x == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->dir_y);
}
/*	1e30 is an arbitrarily chosen high enough number and can be set to infinity,
	if your programming language supports assigning that value */

/*	ray->sidedist_x and ray->sidedist_y are, initially, the distance the ray
	has to travel from its starting position to the first x and y side; they
	are incremented as steps are taken.
	In some cases, 1.0 is added depending on whether the side to the left or
	right, at the top or bottom is used. */
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

/*	Instead of working with Euclidean angles to represent the direction of
	player and rays, it's much easier to work with vectors (x and y coordinates)
	and a camera. The position of the player is always a vector, but now we're
	making the direction a vector as well. This method requires an extra vecor:
	the camera plane. It should always be perpendicular to the direction vector,
	because it represents the surface of the computer screen, whereas the
	direction vector is a point in front of the camera plane. A certain ray of a
	certain x corrdinate of the screen is thus the ray that starts at the player's
	position and goes through that position on the screen, that is, the
	camera plane. */
void	ft_init_dda(t_game *game, int x)
{
	ft_init_ray(&game->plyr, &game->ray, x);
	ft_deltadist(&game->ray);
	game->ray.hit_wall = 0;
	ft_step_sidedist(&game->plyr, &game->ray);
}
