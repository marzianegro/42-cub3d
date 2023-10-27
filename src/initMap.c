/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/27 16:46:43 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_variab(t_game *game)
{
	game->map.map = NULL;
	game->map.row = 0;
	game->map.col = 0;
	game->map.height = 0;
	game->map.width = 0;
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


void	ft_fill_map(t_map *map, char *av, int *count)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map->map = ft_calloc(*count + 1, sizeof(char *));
	if (!map->map)
		ft_error("map allocation failed");
	fd = open(av, O_RDONLY);
	while (map->map && i < *count)
	{
		line = get_next_line(fd);
		if (ft_isloopdigit(line))
			map->map[i++] = ft_strdup(line);
		free(line);
	}
}

void	ft_init_map(t_game *game, t_map *map, char *av)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("nothing to be read");
	while (line)
	{
		count++;
		ft_cf_deets(line, &game->tex);
		free(line);
		line = get_next_line(fd);
	}
	ft_fill_map(map, av, &count);
	close (fd);
}
