/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMapUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:21:54 by marzianegro       #+#    #+#             */
/*   Updated: 2023/11/15 20:13:27 by marzianegro      ###   ########.fr       */
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

int	ft_check_comps_bis(int fd, char **line, int flag)
{
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
		|| *line[0] == '\0')
		;
	else
		ft_error(NULL, "invalid char", *line);
	ft_free((void **)line);
	*line = get_next_line_del(fd);
	return (flag);
}
