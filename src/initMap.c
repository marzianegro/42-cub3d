/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:36:55 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 12:55:10 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	ft_check_chars(game, fd, count_all, count_map);
	close(fd);
	map->row = count_map;
	ft_fill_map(map, fd_map, count_all, count_map);
}

char *get_next_line_del(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	line[len - 1] = '\0';
	return (line);
}

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
			ft_free(&line);
			line = get_next_line_del(fd);
		}
		if (ft_init_textures(&game->map, line) || ft_cf_deets(line, &game->tex))
			flag = 1;
		if (flag == 0 && (ft_strchr(line, '0') || ft_strchr(line, '1')))
			*count_map += 1;
		ft_free(&line);
		line = get_next_line_del(fd);
	}
	close(fd);
}

void	ft_check_chars(t_game *game, int fd, int count_all, int count_map)
{
	int		flag;
	int		i;
	char	*line;

	(void)game;
	i = 0;
	flag = 0;
	line = get_next_line_del(fd);
	if (!line)
		ft_error("nothing to be read");
	while (line && i++ < count_all - count_map)
	{
		if (!ft_strncmp(line, "F ", 2) && (1 & flag >> 0))
			ft_error("duplicate F");
		else if (!ft_strncmp(line, "F ", 2))
			flag |= (1 << 0);
		else if (!ft_strncmp(line, "C ", 2) && (1 & flag >> 1))
			ft_error("duplicate C");
		else if (!ft_strncmp(line, "C ", 2))
			flag |= (1 << 1);
		else if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
			|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
			|| line[0] == '\0')
			;
		else
			ft_error("invalid char");
		ft_free(&line);
		line = get_next_line_del(fd);
	}
	ft_free(&line);
	get_next_line(-42);
	if (flag != 3)
		ft_error("missing F or C");
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
	line = get_next_line_del(fd);
	while (line && i != count_all - count_map)
	{
		ft_free(&line);
		line = get_next_line_del(fd);
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
		line = get_next_line_del(fd);
	}
	close(fd);
}
