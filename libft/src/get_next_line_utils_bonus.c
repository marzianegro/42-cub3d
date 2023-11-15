/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <mnegro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:51:34 by mnegro            #+#    #+#             */
/*   Updated: 2023/11/15 10:28:26 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t		i;
	char		*ret;

	i = 0;
	ret = (char *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	while (i < (nmemb * size))
		ret[i++] = 0;
	return ((void *)ret);
}

char	*ft_clean_buftomem(char *buftomem, int i)
{
	int		j;
	char	*temp;

	j = 0;
	temp = ft_calloc_gnl(ft_strlen(&buftomem[i]) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (buftomem && buftomem[i])
		temp[j++] = buftomem[i++];
	ft_free_gnl(&buftomem);
	return (temp);
}

int	ft_find_newline(char *buftomem)
{
	int	i;

	i = 0;
	while (buftomem && buftomem[i])
		if (buftomem[i++] == '\n')
			return (0);
	return (1);
}

char	*ft_free_gnl(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}
