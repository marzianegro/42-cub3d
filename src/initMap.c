/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/25 15:21:47 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_fill_map(t_map *map, char *av, char *count)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map->map = ft_calloc(count + 1, sizeof(char *));
	if (!map->map)
		ft_error("map allocation failed");
	fd = open(av, O_RDONLY);
	while (map->map && i < count)
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
	ft_fill_map(map, av, count);
	close (fd);
}
