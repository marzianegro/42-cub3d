/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 18:21:58 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// CHECKS TO DO
// - Check file extension
// - Check if there are invalid chars (only 0, 1, N, S, E, and W are valid)
// - Check borders (North, East, South, West): the map has to be surrounded by walls
// - Check if the path is walk-through-able with flood fill?

void	ft_check_ext(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len - 5], ".cub\0", 5))
		ft_error("invalid file map extension");
}

// to be adjusted
void	ft_floodfill(char **mapcopy, int x, int y)
{
	if (mapcopy[y][x] == '0')
	{
		mapcopy[y][x] = '*';
		ft_floodfill(mapcopy, x, y - 1);
		ft_floodfill(mapcopy, x + 1, y);
		ft_floodfill(mapcopy, x, y + 1);
		ft_floodfill(mapcopy, x - 1, y);
	}
}

// to be adjusted
void	ft_afterff(t_map *map, char **mapcopy)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[++y] != NULL)
	{
		x = 1;
		while (x < map->width - 1)
		{
			// ...
			x++;
		}
	}
	ft_freematrix(mapcopy);
}

// to be adjusted
void	ft_checkchecks(t_map *map)
{
	char	**mapcopy;

	ft_floodfill(mapcopy, map->player[X], map->player[Y]);
	ft_afterff(map, mapcopy);
}
