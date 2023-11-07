/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/07 11:33:15 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_print_mtx(char **mtx)
{
	int	y;

	y = 0;
	while (mtx[y])
	{
		ft_printf("%s", mtx[y]);
		y++;
	}
}

void	ft_init_map(t_game *game, t_map *map, char *fd_map)
{
	int		fd;
	int		count_all;
	int		count_map;

	count_all = 0;
	count_map = 0;
	fd = open(fd_map, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	ft_read_map(game, fd, &count_all, &count_map);
	map->row = count_map;
	ft_fill_map(map, fd_map, count_all, count_map);
	close (fd);
}

void	ft_read_map(t_game *game, int fd, int *count_all, int *count_map)
{
	char	*line;
	int		flag;

	line = get_next_line(fd);
	if (!line)
		ft_error("nothing to be read");
	while (line)
	{
		flag = 0;
		*count_all += 1;
		while (*line == '\n')
		{
			*count_all += 1;
			ft_free(&line);
			line = get_next_line(fd);
		}
		if (ft_init_textures(&game->map, line) || ft_cf_deets(line, &game->tex))
			flag = 1;
		if (flag == 0 && (ft_strchr(line, '0') || ft_strchr(line, '1')))
			*count_map += 1;
		ft_free(&line);
		line = get_next_line(fd);
	}
}

void	ft_fill_map(t_map *map, char *fd_map, int count_all, int count_map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(fd_map, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	line = get_next_line(fd);
	while (line && i != count_all - count_map)
	{
		ft_free(&line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	map->map = ft_calloc(count_map + 1, sizeof(char *));
	if (!map->map)
		ft_error("allocation failed");
	while (line)
	{
		map->map[i++] = ft_strdup(line);
		ft_free(&line);
		line = get_next_line(fd);
	}
}
