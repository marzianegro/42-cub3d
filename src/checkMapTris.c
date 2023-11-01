/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapTris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:57:32 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/01 19:49:04 by marzianegro      ###   ########.fr       */
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
	int	j;

	i = 0;
	j = 0;
	while (line[i] && ft_strncmp(&(line[i]), "./", 2))
	{
		while (line[i] == ' ')
			i++;
		if (!ft_check_coor(&(line[i])))
			i += 2;
	}
	if (ft_strncmp(&(line[i]), "./", 2))
		ft_error("invalid NO/SO/EA/WE texture(s)");
	*path = ft_calloc(ft_strlen(&(line[i])) + 1, sizeof(char));
	if (!*path)
		ft_error("failed (c)allocation");
	while (line[i] && line[i] != '\n')
	{
		(*path)[j] = line[i];
		i++;
		j++;
	}
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

	fd = open(map->north, O_RDONLY);
	if (fd < 0)
		ft_error("invalid NO texture");
	fd = open(map->south, O_RDONLY);
	if (fd < 0)
		ft_error("invalid SO texture");
	fd = open(map->east, O_RDONLY);
	if (fd < 0)
		ft_error("invalid EA texture");
	fd = open(map->west, O_RDONLY);
	if (fd < 0)
		ft_error("invalid WE texture");
}
