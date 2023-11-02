/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initVars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:58:29 by marzianegro       #+#    #+#             */
/*   Updated: 2023/11/02 11:54:39 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_vars(void)
{
	ft_init_map();
	ft_init_plyr();
	ft_init_ray();
	ft_init_tex();
}

void	ft_init_map(void)
{
	t_map	map;

	map.map = NULL;
	map.row = 0;
	map.player[0] = 0;
	map.player[1] = 0;
	map.ceiling = 0;
	map.floor = 0;
	map.north = NULL;
	map.east = NULL;
	map.west = NULL;
	map.south = NULL;
}

void	ft_init_plyr(void)
{
	t_player	plyr;

	plyr.pos_x = 0;
	plyr.pos_y = 0;
	plyr.dir_x = 0;
	plyr.plane_x = 0;
	plyr.plane_y = 0;	
	plyr.step_x = 0;
	plyr.step_y = 0;
	plyr.move_speed = 0;
	plyr.rot_speed = 0;
}

void	ft_init_ray(void)
{
	t_ray	ray;

	ray.camera_x = 0;
	ray.dir_x = 0;
	ray.dir_y = 0;
	ray.pos_x = 0;
	ray.pos_y = 0;
	ray.sidedist_x = 0;
	ray.sidedist_y = 0;
	ray.deltadist_x = 0;
	ray.deltadist_y = 0;
	ray.perpwalldist = 0;
	ray.hit_wall = 0;
	ray.side_wall = 0;
}

void	ft_init_tex(void)
{
	t_texture	tex;

	tex.spt = NULL;
	tex.num = 0;
	tex.height = 0;
	tex.width = 0;
	tex.wall_height = 0;
	tex.wall_start = 0;
	tex.wall_end = 0;
	tex.wall_x = 0;
	tex.pos = 0;
	tex.x_coor = 0;
	tex.y_coor = 0;
	tex.step = 0;
	tex.cf_rgb[0][0] = 0;
	tex.cf_rgb[0][1] = 0;
	tex.cf_rgb[0][2] = 0;
	tex.cf_rgb[1][0] = 0;
	tex.cf_rgb[1][1] = 0;
	tex.cf_rgb[1][2] = 0;
}
