/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 12:57:23 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_map(t_game *game, t_map *map)
{
	char	**mapcopy;

	ft_check_textures(game, map);
	ft_check_elems(game, map);
	mapcopy = ft_mtxdup(map);
	ft_floodfill(game, mapcopy, map->player[X], map->player[Y]);
	ft_free_matrix(mapcopy);
}

char	**ft_mtxdup(t_map *map)
{
	char	**dup;
	int		y;

	y = 0;
	dup = ft_calloc(map->row + 1, sizeof(char *));
	if (!dup)
		ft_error("allocation failed");
	while (map->map[y] != NULL)
	{
		dup[y] = ft_strdup(map->map[y]);
		y++;
	}
	return (dup);
}

void	ft_floodfill(t_game *game, char **mapcopy, int x, int y)
{
	if (mapcopy[y][x] == '0' || mapcopy[y][x] == 'N' ||
		mapcopy[y][x] == 'S' || mapcopy[y][x] == 'E' ||
		mapcopy[y][x] == 'W')
	{
		mapcopy[y][x] = '*';
		ft_floodfill(game, mapcopy, x, y - 1);
		ft_floodfill(game, mapcopy, x + 1, y);
		ft_floodfill(game, mapcopy, x, y + 1);
		ft_floodfill(game, mapcopy, x - 1, y);
	}
	else if (mapcopy[y][x] == '*' || mapcopy[y][x] == '1')
		return ;
	else if (mapcopy[y][x] != '1')
		ft_exit(game, "path non walk-through-able");
}
