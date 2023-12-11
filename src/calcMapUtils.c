/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcMapUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:24:20 by btani             #+#    #+#             */
/*   Updated: 2023/11/17 15:13:37 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_freetrim(char *s1, char del)
{
	size_t	i;
	size_t	j;
	char	*trimmed_str;

	trimmed_str = NULL;
	if (s1)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && del == s1[i])
			i++;
		while (s1[j - 1] && del == s1[j - 1] && j > i)
			j--;
		trimmed_str = (char *)ft_calloc((j - i + 1), sizeof(char));
		if (trimmed_str)
			ft_strlcpy(trimmed_str, &s1[i], j - i + 1);
	}
	ft_free((void **)&s1);
	return (trimmed_str);
}

int	ft_isloopdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
		i++;
	if (s[i] == 0)
		return (0);
	return (1);
}
