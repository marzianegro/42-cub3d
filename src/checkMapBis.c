/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapBis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 15:17:50 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_rows(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.col)
	{
		if (game->map.map[0][x] != WALL)
			ft_error("wall missing (row)", game);
		else if (game->map.map[game->map.row - 1][x] != WALL)
			ft_error("wall missing (rowww)", game);
		x++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		if ((int)ft_strlen(game->map.map[y]) != game->map.col)
			ft_error("map incomplete", game);
		if (game->map.map[y][0] != WALL)
			ft_error("wall missingin (col)", game);
		else if (game->map.map[y][game->map.col - 1] != WALL)
			ft_error("wall missing in (colll)", game);
		y++;
	}
}

void	ft_check_components(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (!ft_strchr("01NSEW", game->map.map[y][x]))
				ft_error("unknown char", game);
			else if (ft_strchr("NSEW", game->map.map[y][x]))
			{
				PLAYER = game->map.map[y][x];
				game->map.player++;
				game->map.player[X] = x;
				game->map.player[Y] = y;
			}
			x++;
		}
		y++;
	}
}
