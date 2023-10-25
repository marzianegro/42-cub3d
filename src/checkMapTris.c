/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapTris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:57:32 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/25 19:21:21 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_save_path(t_map *map, int *y, char *path)
{
	int	x;

	x = 0;
	while (map->map[*y])
	{
		while (map->map[*y][x])
		{
			while (map->map[*y][x] == ' ')
				x++;
			if (!ft_strncmp(map->map[*y], "NO ", 3) || !ft_strncmp(map->map[*y], "SO ", 3)
				|| !ft_strncmp(map->map[*y], "EA ", 3) || !ft_strncmp(map->map[*y], "WE ", 3))
				x += 2;
			*path = ft_calloc(ft_strlen(map->map[*y][x]) + 1, sizeof(char));
		}
	}
}

void	ft_init_textures(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		if (!ft_strncmp(map->map[y], "NO ", 3))
			ft_save_path(map, &y, &map->north);
		else if (!ft_strncmp(map->map[y], "SO ", 3))
			ft_save_path(map, &y, &map->south);
		else if (!ft_strncmp(map->map[y], "EA ", 3))
			ft_save_path(map, &y, &map->east);
		else if (!ft_strncmp(map->map[y], "WE ", 3))
			ft_save_path(map, &y, &map->west);
		y++;
	}
	ft_check_textures(map);
}

void	ft_check_textures(t_map *map)
{
	int	fd;

	fd = open(map->north, O_RDONLY);
	if (fd < 0)
		ft_error("invalid NO texture");
	fd = open(map->south, O_RDONLY);
	if (fd < 0)
		ft_error("invalid SO texture");
	fd = open(map->east, O_RDONLY);
	if (fd < 0)
		ft_error("invalid EA texture");
	fd = open(map->west, O_RDONLY);
	if (fd < 0)
		ft_error("invalid WE texture");
}
