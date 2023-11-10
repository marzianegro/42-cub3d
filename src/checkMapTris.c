/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapTris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:57:32 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/10 12:36:21 by marzianegro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_coor(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "EA ", 3) || !ft_strncmp(str, "WE ", 3))
		return (0);
	return (1);
}

void	ft_save_path(char *line, char **path)
{
	int	i;

	i = 2;
	// free line
	if (*path)
		ft_error("more than one NO/SO/EA/WE texture");
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

void	ft_check_textures(t_game *game, t_map *map)
{
	int	fd;

	fd = open(map->north, O_RDONLY);
	if (fd < 0)
		ft_exit(game, "invalid NO texture");
	close(fd);
	fd = open(map->south, O_RDONLY);
	if (fd < 0)
		ft_exit(game, "invalid SO texture");
	close(fd);
	fd = open(map->east, O_RDONLY);
	if (fd < 0)
		ft_exit(game, "invalid EA texture");
	close(fd);
	fd = open(map->west, O_RDONLY);
	if (fd < 0)
		ft_exit(game, "invalid WE texture");
	close(fd);
}
