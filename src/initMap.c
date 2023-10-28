/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/28 17:00:24 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_variab(t_game *game)
{
	game->map.map = NULL;
	game->map.row = 0;
	game->map.player[0] = 0;
	game->map.player[1] = 0;
	game->map.ceiling = 0;
	game->map.floor = 0;
	game->map.north = NULL;
	game->map.east = NULL;
	game->map.west = NULL;
	game->map.south = NULL;

	game->plyr.step_x = 0;
	game->plyr.step_y = 0;
	game->plyr.move_speed = 0;
	game->plyr.rot_speed = 0;

	game->ray.sidedist_x = 0;
	game->ray.sidedist_y = 0;
	game->ray.deltadist_x = 0;
	game->ray.deltadist_y = 0;
	game->ray.perpwalldist = 0;
	game->ray.hit_wall = 0;
	game->ray.side_wall = 0;

	game->tex.spt = NULL;
	game->tex.num = 0;
	game->tex.height = 0;
	game->tex.width = 0;
	game->tex.wall_height = 0;
	game->tex.wall_start = 0;
	game->tex.wall_end = 0;
	game->tex.wall_x = 0;
	game->tex.pos = 0;
	game->tex.x_coor = 0;
	game->tex.y_coor = 0;
	game->tex.step = 0;
}

static void	ft_print_mtx(char **mtx)
{
	int	y;

	y = 0;
	while (mtx[y])
	{
		ft_printf("%s", mtx[y]);
		y++;
	}
}

void	ft_fill_map(t_map *map, char *fd_map, int count_a, int count_b)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(fd_map, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	line = get_next_line(fd);
	while (line && i != count_a - count_b)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	map->map = ft_calloc(count_b + 1, sizeof(char *));
	if (!map->map)
		ft_error("map allocation failed");
	while (line)
	{
		map->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	ft_print_mtx(map->map);
}

void	ft_init_map(t_game *game, t_map *map, char *fd_map)
{
	int		fd;
	char	*line;
	int		flag;
	int		count_a;
	int		count_b;

	count_a = 0;
	count_b = 0;
	fd = open(fd_map, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	line = get_next_line(fd);
	if (!line)
		ft_error("nothing to be read");
	while (line)
	{
		flag = 0;
		count_a++;
		while (*line == '\n')
		{
			count_a++;
			free(line);
			line = get_next_line(fd);
		}
		if (ft_init_textures(map, line) || ft_cf_deets(line, &game->tex))
			flag = 1;
		if (flag == 0 && (ft_strchr(line, '0') || ft_strchr(line, '1')))
			count_b++;
		free(line);
		line = get_next_line(fd);
	}
	map->row = count_b;
	ft_fill_map(map, fd_map, count_a, count_b);
	close (fd);
}
