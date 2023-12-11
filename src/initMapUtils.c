/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMapUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:21:54 by marzianegro       #+#    #+#             */
/*   Updated: 2023/11/17 15:26:05 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line_del(int fd)
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

void	ft_read_map_bis(int fd, char **line, int *count_all, int *count_map)
{
	*count_all += 1;
	if (*count_map != 0 && *line && (*line)[0] == '\0')
		*count_map += 1;
	ft_free((void **)line);
	*line = get_next_line_del(fd);
}

int	ft_check_comps_bis(int fd, char **line, int flag)
{
	int	i;

	i = -1;
	if (!ft_strncmp(*line, "F ", 2) && (1 & flag >> 0))
		ft_error(NULL, "duplicate F", *line);
	else if (!ft_strncmp(*line, "F ", 2))
		flag |= (1 << 0);
	else if (!ft_strncmp(*line, "C ", 2) && (1 & flag >> 1))
		ft_error(NULL, "duplicate C", *line);
	else if (!ft_strncmp(*line, "C ", 2))
		flag |= (1 << 1);
	else if (!ft_strncmp(*line, "NO ", 3) || !ft_strncmp(*line, "SO ", 3)
		|| !ft_strncmp(*line, "WE ", 3) || !ft_strncmp(*line, "EA ", 3)
		|| (*line)[0] == '\0')
		;
	else
	{
		while ((*line)[++i])
			if ((*line)[i] != ' ' && (*line)[i] != '\t')
				ft_error(NULL, "invalid char", *line);
	}
	ft_free((void **)line);
	*line = get_next_line_del(fd);
	return (flag);
}
