/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/27 19:35:44 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// CHECKS TO DO
// - Check if the path is walk-through-able with flood fill

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

void	ft_check_map(char **av, t_map *map)
{
	char	**mapcopy;

	(void)av;
	// ft_count_map(av, map);
	ft_check_textures(map);
	ft_check_rows(map);
	ft_check_columns(map);
	mapcopy = ft_mtxdup(map);
	ft_floodfill(mapcopy, map->player[X], map->player[Y]);
	ft_afterff(map, mapcopy);
}
