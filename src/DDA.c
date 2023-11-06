/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:00:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/06 19:52:52 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_dda(t_map *map, t_player *plyr, t_ray *ray, t_texture *tex)
{
	while (ray->hit_wall == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->pos_x += plyr->step_x;
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
