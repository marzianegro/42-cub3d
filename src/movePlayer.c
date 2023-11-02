/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/01 20:23:16 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_forward(t_game *game, t_map *map)
{
	if (map->map[(int)(game->plyr.pos_x + game->plyr.dir_x
			* game->plyr.move_speed)][(int)game->plyr.pos_x] == false)
		game->plyr.pos_x += game->plyr.dir_x * game->plyr.move_speed;
	if (map->map[(int)game->plyr.pos_x][(int)(game->plyr.pos_y
		+ game->plyr.dir_y * game->plyr.move_speed)] == false)
		game->plyr.pos_y += game->plyr.dir_y * game->plyr.move_speed;
}

void	ft_left(t_game *game, t_map *map)
{
	if (map->map[(int)(game->plyr.pos_x - game->plyr.dir_y
			* game->plyr.move_speed)][(int)game->plyr.pos_y] == false)
		game->plyr.pos_x -= game->plyr.dir_y * game->plyr.move_speed;
	if (map->map[(int)game->plyr.pos_x][(int)(game->plyr.pos_y
		+ game->plyr.dir_x * game->plyr.move_speed)] == false)
		game->plyr.pos_y += game->plyr.dir_x * game->plyr.move_speed;
}

void	ft_backward(t_game *game, t_map *map)
{
	if (map->map[(int)(game->plyr.pos_x - game->plyr.dir_x
			* game->plyr.move_speed)][(int)game->plyr.pos_x] == false)
		game->plyr.pos_x -= game->plyr.dir_x * game->plyr.move_speed;
	if (map->map[(int)game->plyr.pos_x][(int)(game->plyr.pos_y
		- game->plyr.dir_y * game->plyr.move_speed)] == false)
		game->plyr.pos_y -= game->plyr.dir_y * game->plyr.move_speed;
}

void	ft_right(t_game *game, t_map *map)
{
	if (map->map[(int)(game->plyr.pos_x + game->plyr.dir_y
			* game->plyr.move_speed)][(int)game->plyr.pos_y] == false)
		game->plyr.pos_x += game->plyr.dir_y * game->plyr.move_speed;
	if (map->map[(int)game->plyr.pos_x][(int)(game->plyr.pos_y
		- game->plyr.dir_x * game->plyr.move_speed)] == false)
		game->plyr.pos_y -= game->plyr.dir_x * game->plyr.move_speed;
}
