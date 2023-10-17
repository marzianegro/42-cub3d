/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:00:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 11:37:37 by mnegro           ###   ########.fr       */
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
			ray->pos_x += plyr->step_x;
			ray->side_wall = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->pos_y += plyr->step_y;
			ray->side_wall = 0;
		}
		if (map->map[(int)ray->pos_x][(int)ray->pos_y] == '1')
			ray->hit_wall = 1;
		}
}
