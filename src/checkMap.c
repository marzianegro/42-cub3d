/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 15:17:48 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// CHECKS TO DO
// - Check if the path is walk-through-able with flood fill

void	ft_check_ext(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len - 4], ".cub", 4))
		ft_error("invalid file map extension");
}

char	**ft_mtxdup(t_map *map)
{
	char	**dup;
	int		y;

	y = 0;
	dup = ft_calloc(map->height + 1, sizeof(char *));
	while (map->map[y] != NULL)
	{
		dup[y] = ft_strdup(map->map[y]);
		y++;
	}
	return (dup);
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
	ft_free_matrix(mapcopy);
}

void	ft_check_map(t_map *map)
{
	char	**mapcopy;

	ft_check_rows(map);
	ft_check_columns(map);
	//if (game->map.player != 1)
	//	ft_error("there can only be one player");
	mapcopy = ft_mtxdup(map);
	ft_floodfill(mapcopy, map->player[X], map->player[Y]);
	ft_afterff(map, mapcopy);
}
