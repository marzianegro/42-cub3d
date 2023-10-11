/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotPlane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:20:24 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/08 15:15:50 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rot_left(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->plyr->dir_x;
	oldplane_x = game->plyr->plane_x;
	game->plyr->dir_x = game->plyr->dir_x * cos(time->rot_speed)
		- game->plyr->dir_y * sin(time->rot_speed);
	game->plyr->dir_y = olddir_x * sin(time->rot_speed)
		+ game->plyr->dir_y * cos(time->rot_speed);
	game->plyr->plane_x = game->plyr->plane_x * cos(time->rot_speed)
		- game->plyr->plane_y * sin(time->rot_speed);
	game->plyr->plane_y = oldplane_x * sin(time->rot_speed)
		+ game->plyr->plane_y * cos(time->rot_speed);
}

void	ft_rot_right(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->plyr->dir_x;
	oldplane_x = game->plyr->plane_x;
	game->plyr->dir_x = game->plyr->dir_x * cos(time->(-rot_speed))
		- game->plyr->dir_y * sin(time->(-rot_speed));
	game->plyr->dir_y = olddir_x * sin(time->(-rot_speed))
		+ game->plyr->dir_y * cos(time->(-rot_speed));
	game->plyr->plane_x = game->plyr->plane_x * cos(time->(-rot_speed))
		- game->plyr->plane_y * sin(time->(-rot_speed));
	game->plyr->plane_y = oldplane_x * sin(time->(-rot_speed))
		+ game->plyr->plane_y * cos(time->(-rot_speed));
}
