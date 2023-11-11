/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMapUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marzianegro <marzianegro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:21:54 by marzianegro       #+#    #+#             */
/*   Updated: 2023/11/11 13:35:36 by marzianegro      ###   ########.fr       */
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

int	ft_check_comps_bis(char *line, int flag)
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
	return (flag);
}
