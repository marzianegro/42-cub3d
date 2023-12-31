/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:57:32 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/17 15:13:45 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_save_path(char *line, char **path)
{
	int	i;

	i = 2;
	if (*path)
		ft_error(NULL, "more than one NO/SO/EA/WE texture", line);
	while (line[i] == ' ')
		i++;
	*path = ft_strdup(&line[i]);
}

bool	ft_init_textures(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		ft_save_path(line, &map->north);
	else if (!ft_strncmp(line, "SO ", 3))
		ft_save_path(line, &map->south);
	else if (!ft_strncmp(line, "EA ", 3))
		ft_save_path(line, &map->east);
	else if (!ft_strncmp(line, "WE ", 3))
		ft_save_path(line, &map->west);
	else
		return (false);
	return (true);
}

void	ft_check_textures(t_map *map)
{
	int	fd;

	if (!map->north || !map->south || !map->east
		|| !map->west)
		ft_error(NULL, "missing NO/SO/EA/WE texture", NULL);
	fd = open(map->north, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, "invalid NO texture", NULL);
	close(fd);
	fd = open(map->south, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, "invalid SO texture", NULL);
	close(fd);
	fd = open(map->east, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, "invalid EA texture", NULL);
	close(fd);
	fd = open(map->west, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, "invalid WE texture", NULL);
	close(fd);
}
