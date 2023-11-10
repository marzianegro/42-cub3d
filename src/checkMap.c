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
	ft_check_textures(game, map);
	ft_check_elems(game, map);
	ft_floodfill(game, &game->map, map->player[X], map->player[Y]);
}

void	ft_floodfill(t_game *game, t_map *map, int x, int y)
{
	if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'N' ||
		game->map.map[y][x] == 'S' || game->map.map[y][x] == 'E' ||
		game->map.map[y][x] == 'W')
	{
		game->map.map[y][x] = '*';
		ft_floodfill(game, map, x, y - 1);
		ft_floodfill(game, map, x + 1, y);
		ft_floodfill(game, map, x, y + 1);
		ft_floodfill(game, map, x - 1, y);
	}
	else if (game->map.map[y][x] == '*' || game->map.map[y][x] == '1')
		return ;
	else if (game->map.map[y][x] != '1')
		ft_exit(game, "path non walk-through-able");
}
