/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkMap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:34:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/07 16:13:39 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_ext(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][len - 5], ".cub\0", 5))
		ft_error("invalid file map extension!");
}

// to be adjusted
void	ft_floodfill(char **mapcopy, int x, int y)
{
	if (mapcopy[y][x] == '0' || mapcopy[y][x] == 'E'
		|| mapcopy[y][x] == 'P' || mapcopy[y][x] == 'C')
	{
		if (mapcopy[y][x] == 'E')
		{
			mapcopy[y][x] = 'O';
			return ;
		}
		else
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
			if (mapcopy[y][x] == 'E' || mapcopy[y][x] == 'C')
			{
				ft_freematrix(mapcopy);
				ft_exit(map, 3);
			}
			else if (mapcopy[y][x] != '*' && mapcopy[y][x] != '1'
				&& mapcopy[y][x] != '0' && mapcopy[y][x] != 'O')
			{
				ft_freematrix(mapcopy);
				ft_exit(map, 2);
			}
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
