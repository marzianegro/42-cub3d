/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/10/11 11:19:54 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_map(t_game *game, char *av)
{
    int     i;
	int		fd;
	int		count;
	char	*line;

    i = 0;
	count = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
		ft_error("impossible to open fd");
	line = get_next_line(fd);
	if (line == NULL)
		ft_error("nothing to be read");
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
    game->map = ft_calloc(count + 1, sizeof(char *));
    if (!game->map)
		ft_error("map allocation failed");
    while (game->map[i] && i < count)
        game->map[++i] = get_next_line(fd);
    close (fd);  
}
