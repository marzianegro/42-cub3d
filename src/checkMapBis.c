/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapBis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/27 20:04:56 by mnegro           ###   ########.fr       */
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

// void	ft_count_map(t_map *map)
// {
// 	while ()
// 	{
		
// 		if (map->map[y][x] != '0') || !ft_strchr(map->map[y][x], '1') || !ft_strchr(map->map[y][x], 'N')
// 			|| !ft_strchr(map->map[y][x], 'S') || !ft_strchr(map->map[y][x], 'E') || !ft_strchr(map->map[y][x], 'W'))
// 		{
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		else
// 		{
// 			map->row++;
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 	}
// }

// void	ft_check_columns(t_map *map)
// {
// 	int	x;

// 	x = 0;
// 	while (x < map->col)
// 	{
// 		if (map->map[0][x] != WALL)
// 			ft_error("wall missing (col)");
// 		else if (map->map[map->row - 1][x] != WALL)
// 			ft_error("wall missing (colll)");
// 		x++;
// 	}
// }

void	ft_check_rows(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (map->map[y][x])
		{
			// controlli su prima e ultima riga
			while (map->map[y][x] == ' ' || map->map[y][x] == '\t')
				x++;
			if (map->map[y][x] != WALL)
				ft_error("row is missing a wall");
			x++;
		}
		// funzione che cerca 1 all'inizio e alla fine delle righe centrali
		y++;
	}
}

void	ft_check_components(t_map *map)
{
	int	x;
	int	y;
	int	count;

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
