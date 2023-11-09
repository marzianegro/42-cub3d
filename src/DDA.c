/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:00:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/09 11:00:01 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* The algorithm performed here is based on Digital Differential Analysis. 
	It works by checking at every side of a wall that the ray encounters. By
	giving each square a width of 1, each side of a wall is an intefer value,
	and the places in between have a value after the point. This way, the step
	size isn't constant, but depends on the distance to the next side.
	In short, it's a loop that increments the ray by one square every time,
	until a wall is hit. Each time, it jumps a square either in the x direction
	(with plyr->step_x) or in the y direction (with plyr->step_y), but it
	always jumps one square at a time. Whether it will jump in the negative
	or the steps variables, which are always either -1 or 1. */
void	ft_dda(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex)
{
	while (ray->hit_wall == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->pos_x += plyr->step_x;
			// the x side of the wall was hit
			ray->side_wall = 0;
			if (ray->dir_x < 0)
				tex->num = 0;
			else
				tex->num = 1;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->pos_y += plyr->step_y;
			// the y side of the wall was hit
			ray->side_wall = 1;
			if (ray->dir_y < 0)
				tex->num = 2;
			else
				tex->num = 3;
		}
		if (map->map[(int)ray->pos_y][(int)ray->pos_x] == '1')
			ray->hit_wall = 1;
	}
}
