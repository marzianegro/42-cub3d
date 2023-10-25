/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapBis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:17 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/25 17:58:43 by mnegro           ###   ########.fr       */
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

void	ft_count_map(char **av, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(*av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_init_textures();
		if (!ft_findset(line, "01NSEW"))
		{
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			map->row++;
			free(line);
			line = get_next_line(fd);
		}
	}
}

void	ft_check_columns(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->col)
	{
		if (map->map[0][x] != WALL)
			ft_error("wall missing (col)");
		else if (map->map[map->row - 1][x] != WALL)
			ft_error("wall missing (colll)");
		x++;
	}
}

void	ft_check_rows(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->row)
	{
		while (map->map[0][x])
		{
			map->col++;
			x++;
		}
		if ((int)ft_strlen(map->map[y]) != map->col)
			ft_error("map incomplete");
		if (map->map[y][0] != WALL)
			ft_error("wall missing (row)");
		else if (map->map[y][map->col - 1] != WALL)
			ft_error("wall missing (rowwww)");
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
