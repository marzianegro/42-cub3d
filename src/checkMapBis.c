/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapBis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/28 16:56:46 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_ext(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len - 4], ".cub", 4))
		ft_error("invalid file map extension");
}

void	ft_check_walls(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (y == 0 || y == map->row)
			{
				while (map->map[y][x] == ' ' || map->map[y][x] == '\t')
					x++;
				if (map->map[y][x] != '1'
					&& (map->map[y][x] == '\n' && map->map[y][x + 1] != '\0'))
					ft_error("1row is missing a wall");
				x++;
			}
			else
			{
				while (map->map[y][x] == ' ' || map->map[y][x] == '\t')
					x++;
				if (map->map[y][x] != '1')
					ft_error("2row is missing a wall");
				while (map->map[y][x + 1] != '\n'
					&& map->map[y][x + 1] != '\0')
					x++;
				if (map->map[y][x] != '1')
					ft_error("3row is missing a wall");
				else
					break ;
			}
		}
		y++;
	}
}

// void	ft_check_components(t_map *map)
// {
// 	int	x;
// 	int	y;
// 	int	count;

// 	count = 0;
// 	y = 0;
// 	while (y < map->row)
// 	{
// 		x = 0;
// 		while (x < map->col)
// 		{
// 			if (!ft_strchr("01NSEW", map->map[y][x]))
// 				ft_error("unknown char");
// 			else if (ft_strchr("NSEW", map->map[y][x]))
// 			{
// 				count++;
// 				if (count != 1)
// 					ft_error("there can only be one player");
// 				map->player[X] = x;
// 				map->player[Y] = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
