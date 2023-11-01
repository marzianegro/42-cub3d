/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/01 20:12:17 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
