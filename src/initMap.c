/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:03 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_map(t_game *game, t_map *map, char *av)
{
    int     i;
	int		fd;
	int		count;
	char	*line;

    i = 0;
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
		line = get_next_line(fd);
	}
    map = ft_calloc(count + 1, sizeof(char *));
    if (!map)
		ft_error("map allocation failed");
    while (map->map[i] && i < count)
        map->map[++i] = get_next_line(fd);
    close (fd);  
}
