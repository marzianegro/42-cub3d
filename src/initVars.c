/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initVars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:58:29 by marzianegro       #+#    #+#             */
/*   Updated: 2023/11/17 15:20:18 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_vars(t_game *game)
{
	ft_init_map_vars(game);
	ft_init_plyr_vars(game);
	ft_init_ray_vars(game);
	ft_init_tex_vars(game);
}

void	ft_init_map_vars(t_game *game)
{
	game->map.map = NULL;
	game->map.row = 0;
	game->map.player[Y] = 0;
	game->map.player[X] = 0;
	game->map.plyr_cardinal = 0;
	game->map.ceiling = 0;
	game->map.floor = 0;
	game->map.north = NULL;
	game->map.east = NULL;
	game->map.west = NULL;
	game->map.south = NULL;
}

void	ft_init_plyr_vars(t_game *game)
{
	game->plyr.pos_x = 0;
	game->plyr.pos_y = 0;
	game->plyr.dir_x = 0;
	game->plyr.dir_y = 0;
	game->plyr.plane_x = 0;
	game->plyr.plane_y = 0;
	game->plyr.step_x = 0;
	game->plyr.step_y = 0;
	game->plyr.move_speed = 0.05;
	game->plyr.rot_speed = 0;
}

void	ft_init_ray_vars(t_game *game)
{
	game->ray.camera_x = 0;
	game->ray.dir_x = 0;
	game->ray.dir_y = 0;
	game->ray.pos_x = 0;
	game->ray.pos_y = 0;
	game->ray.sidedist_x = 0;
	game->ray.sidedist_y = 0;
	game->ray.deltadist_x = 0;
	game->ray.deltadist_y = 0;
	game->ray.perpwalldist = 0;
	game->ray.hit_wall = 0;
	game->ray.side_wall = 0;
}

void	ft_init_tex_vars(t_game *game)
{
	game->tex.num = 0;
	game->tex.height = 0;
	game->tex.width = 0;
	game->tex.wall_height = 0;
	game->tex.wall_start = 0;
	game->tex.wall_end = 0;
	game->tex.wall_x = 0;
	game->tex.pos = 0;
	game->tex.x_coor = 0;
	game->tex.y_coor = 0;
	game->tex.step = 0;
	game->tex.cf_rgb[0][0] = 0;
	game->tex.cf_rgb[0][1] = 0;
	game->tex.cf_rgb[0][2] = 0;
	game->tex.cf_rgb[1][0] = 0;
	game->tex.cf_rgb[1][1] = 0;
	game->tex.cf_rgb[1][2] = 0;
}
