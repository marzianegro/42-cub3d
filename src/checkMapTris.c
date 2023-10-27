/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapTris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:57:32 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/27 17:32:47 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_coor(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "WE ", 3))
		return (0);
	return (1);
}

void	ft_save_path(t_map *map, int *y, char **path)
{
	int	x;
	int	i;

	x = 0;
	i = 0;

	while (map->map[*y][x] && ft_strncmp(&(map->map[*y][x]), "./", 2))
	{
		while (map->map[*y][x] == ' ')
			x++;
		if (!ft_check_coor(&(map->map[*y][x])))
			x += 2;
	}
	if (ft_strncmp(&(map->map[*y][x]), "./", 2))
		ft_error("invalid NO/SO/EA/WE texture(s)");
	*path = ft_calloc(ft_strlen(&(map->map[*y][x])) + 1, sizeof(char));
	if (!*path)
		ft_error("failed (c)allocation");
	while (map->map[*y][x] && map->map[*y][x] != '\n')
	{
		(*path)[i] = map->map[*y][x];
		i++;
		x++;
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
