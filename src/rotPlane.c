/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotPlane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:20:24 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/15 21:26:47 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*	When the player rotates, the camera has to rotate as well, so both the
	direction vector and the plane vector have to be rotated. Then, the
	rays will all automatically rotate as well.
	When rotating around, the values of plyr->dir and plyr->plane change,
	but they always remain perpendicular to each other and of the same
	length. */
void	ft_rot_right(t_game *game)
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

void	ft_rot_left(t_game *game)
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
