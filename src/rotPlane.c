/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotPlane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:20:24 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/06 19:55:17 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rot_left(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->plyr.dir_x;
	oldplane_x = game->plyr.plane_x;
	game->plyr.dir_x = game->plyr.dir_x * cos(game->plyr.rot_speed)
		- game->plyr.dir_y * sin(game->plyr.rot_speed);
	game->plyr.dir_y = olddir_x * sin(game->plyr.rot_speed)
		+ game->plyr.dir_y * cos(game->plyr.rot_speed);
	game->plyr.plane_x = game->plyr.plane_x * cos(game->plyr.rot_speed)
		- game->plyr.plane_y * sin(game->plyr.rot_speed);
	game->plyr.plane_y = oldplane_x * sin(game->plyr.rot_speed)
		+ game->plyr.plane_y * cos(game->plyr.rot_speed);
}

void	ft_rot_right(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->plyr.dir_x;
	oldplane_x = game->plyr.plane_x;
	game->plyr.dir_x = game->plyr.dir_x * cos(-game->plyr.rot_speed)
		- game->plyr.dir_y * sin(-game->plyr.rot_speed);
	game->plyr.dir_y = olddir_x * sin(-game->plyr.rot_speed)
		+ game->plyr.dir_y * cos(-game->plyr.rot_speed);
	game->plyr.plane_x = game->plyr.plane_x * cos(-game->plyr.rot_speed)
		- game->plyr.plane_y * sin(-game->plyr.rot_speed);
	game->plyr.plane_y = oldplane_x * sin(-game->plyr.rot_speed)
		+ game->plyr.plane_y * cos(-game->plyr.rot_speed);
}
