/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/18 17:46:36 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_map(t_game *game, t_map *map, char *av)
{
	int		i;
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
		free(line);
		line = get_next_line(fd);
	}
    map->map = ft_calloc(count + 1, sizeof(char *));
    if (!map->map)
		ft_error("map allocation failed");
	fd = open(av, O_RDONLY);
    while (map->map && i < count)
	{
		char *str = get_next_line(fd);
		if (ft_isloopdigit(str))
        	map->map[i++] = ft_strdup(str);
		free(str);
	}
    close (fd);
}
