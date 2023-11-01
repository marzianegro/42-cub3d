/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/01 19:56:36 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	ft_floodfill(char **mapcopy, int x, int y)
{
	if (mapcopy[y][x] == '0' || mapcopy[y][x] == 'N' ||
		mapcopy[y][x] == 'S' || mapcopy[y][x] == 'E' || 
		mapcopy[y][x] == 'W')
	{
		mapcopy[y][x] = '*';
		ft_floodfill(mapcopy, x, y - 1);
		ft_floodfill(mapcopy, x + 1, y);
		ft_floodfill(mapcopy, x, y + 1);
		ft_floodfill(mapcopy, x - 1, y);
	}
}

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
			if (mapcopy[y][x] != '*' || mapcopy[y][x] != '1')
				ft_error("path non walk-through-able")
			x++;
		}
	}
	ft_free_matrix(mapcopy);
}

void	ft_check_map(t_map *map)
{
	char	**mapcopy;

	ft_check_textures(map);
	ft_check_walls(map);
	mapcopy = ft_mtxdup(map);
	ft_floodfill(mapcopy, map->player[X], map->player[Y]);
	ft_afterff(map, mapcopy);
}
