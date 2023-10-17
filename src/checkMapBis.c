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

void	ft_check_rows(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->col)
	{
		if (map->map[0][x] != WALL)
			ft_error("wall missing (row)");
		else if (map->map[map->row - 1][x] != WALL)
			ft_error("wall missing (rowww)");
		x++;
	}
}

void	ft_check_columns(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->row)
	{
		if ((int)ft_strlen(map->map[y]) != map->col)
			ft_error("map incomplete");
		if (map->map[y][0] != WALL)
			ft_error("wall missingin (col)");
		else if (map->map[y][map->col - 1] != WALL)
			ft_error("wall missing in (colll)");
		y++;
	}
}

//se trovo F salvo in floor_rgb r, g, b
//se trovo C salvo in ceiling_rgb r, g, b
//se trovo FF o CC sovrascrivi quello precedente
void	ft_check_components(t_map *map)
{
	int	x;
	int	y;
	int count;

	count = 0;
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (!ft_strchr("01NSEW", map->map[y][x]))
				ft_error("unknown char");
			else if (ft_strchr("NSEW", map->map[y][x]))
			{
				count++;
				if (count != 1)
					ft_error("there can only be one player");
				map->player[X] = x;
				map->player[Y] = y;
			}
			x++;
		}
		y++;
	}
}
