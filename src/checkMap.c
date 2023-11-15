/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <mnegro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/15 20:38:21 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_ext(char **av)
{
	int	len;
	int	file_len;

	len = ft_strlen(av[1]);
	if (len <= 4)
		ft_error(NULL, "invalid map file", NULL);
	file_len = len;
	while (file_len && av[1][file_len] != '/')
		file_len--;
	if (av[1][file_len] == '/')
		file_len++;
	if (len - file_len <= 4)
		ft_error(NULL, "invalid map file", NULL);
	else if (!ft_strnstr(&av[1][len - 4], ".cub", 4))
		ft_error(NULL, "invalid map file extension", NULL);
}

void	ft_check_elems(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			while (map->map[y][x] == ' ' || map->map[y][x] == '\t')
				x++;
			if (!ft_strchr("01NSWE", map->map[y][x]))
				ft_error(NULL, "unknown char", NULL);
			x++;
		}
		y++;
	}
	ft_check_elems_bis(map);
}

void	ft_check_elems_bis(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (ft_strchr("NSWE", map->map[y][x]))
			{
				count++;
				map->player[X] = x;
				map->player[Y] = y;
				map->plyr_cardinal = map->map[y][x];
			}
			x++;
		}
		y++;
	}
	if (count < 1)
		ft_error(NULL, "player missing", NULL);
	else if (count > 1)
		ft_error(NULL, "there can only be one player", NULL);
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
		ft_error(NULL, "path non walk-through-able", NULL);
}

void	ft_check_map(t_game *game, t_map *map)
{
	ft_check_textures(map);
	ft_check_elems(map);
	ft_floodfill(game, &game->map, map->player[X], map->player[Y]);
}
