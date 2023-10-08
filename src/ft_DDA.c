/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_DDA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:00:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:27 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Digital Differential Analysis
void	ft_dda(t_map *map, t_player *plyr, t_ray *ray)
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
		if (map->map[ray->map_x][ray->map_y == '1')
			ray->side_wall = 1;
	}
}
