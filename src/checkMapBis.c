/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapBis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/09 10:01:12 by marzianegro      ###   ########.fr       */
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

void	ft_check_elems(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			while (map->map[y][x] == ' ' || map->map[y][x] == '\t'
				|| map->map[y][x] == '\n')
				x++;
			if (!ft_strchr("01NSWE", map->map[y][x]))
				ft_exit(game, "unknown char");
			x++;
		}
		y++;
	}
	ft_check_elems_bis(game, map);
}

void	ft_check_elems_bis(t_game *game, t_map *map)
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
			}
			x++;
		}
		y++;
	}
	if (count < 1)
		ft_exit(game, "player missing");
	else if (count > 1)
		ft_exit(game, "there can only be one player");
}
