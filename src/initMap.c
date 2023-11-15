/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <mnegro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/15 12:47:06 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_map(t_game *game, int fd, int *count_all, int *count_map)
{
	char	*line;
	int		flag;

	line = get_next_line_del(fd);
	if (!line)
		ft_error("nothing to be read");
	while (line)
	{
		flag = 0;
		*count_all += 1;
		while (!*line)
		{
			*count_all += 1;
			ft_free((void **)&line);
			line = get_next_line_del(fd);
		}
		if (ft_init_textures(&game->map, line) || ft_cf_deets(line, &game->tex))
			flag = 1;
		if (flag == 0 && (ft_strchr(line, '0') || ft_strchr(line, '1')))
			*count_map += 1;
		ft_free((void **)&line);
		line = get_next_line_del(fd);
	}
	close(fd);
}

void	ft_check_comps(int fd, int count_all, int count_map)
{
	int		i;
	char	*line;
	int		flag;

	i = 0;
	line = get_next_line_del(fd);
	flag = 0;
	if (!line)
		ft_error("nothing to be read");
	while (line && i++ < count_all - count_map)
		flag = ft_check_comps_bis(fd, &line, flag);
	ft_free((void **)&line);
	get_next_line(-42);
	if (flag != 3)
		ft_error("missing F or C");
}

void	ft_fill_map(t_map *map, int fd, int count_all, int count_map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line_del(fd);
	while (line && i++ != count_all - count_map)
	{
		ft_free((void **)&line);
		line = get_next_line_del(fd);
	}
	i = 0;
	map->map = ft_calloc(count_map + 1, sizeof(char *));
	if (!map->map)
		ft_error("allocation failed");
	while (line)
	{
		map->map[i++] = ft_strdup(line);
		ft_free((void **)&line);
		line = get_next_line_del(fd);
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
	close(fd);
	fd = open(fd_map, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	ft_check_comps(fd, count_all, count_map);
	close(fd);
	map->row = count_map;
	fd = open(fd_map, O_RDONLY);
	if (fd < 0)
		ft_error("impossible to open fd");
	ft_fill_map(map, fd, count_all, count_map);
	close(fd);
}
